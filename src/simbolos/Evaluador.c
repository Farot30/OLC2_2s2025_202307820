#include "Evaluador.h"
#include "semantico/semantico.h"
#include <string.h>
#include <stdlib.h>
#include <stdio.h>

static ValorSimbolo makeNum(TipoDato tipo, double d){
    ValorSimbolo v; memset(&v,0,sizeof(v));
    v.tipo = tipo; v.inicializado = 1;
    switch(tipo){
        case TIPO_DOUBLE: v.v.d = d; break;
        case TIPO_FLOAT:  v.v.f = (float)d; break;
        case TIPO_INT:    v.v.i = (int)d; break;
        case TIPO_CHAR:   v.v.c = (char)d; break;
        default: break;
    }
    return v;
}

static int esNum(TipoDato t){
    return t==TIPO_INT||t==TIPO_FLOAT||t==TIPO_DOUBLE||t==TIPO_CHAR;
}

ValorSimbolo evaluarExpr(NodoAST* e){
    ValorSimbolo r; memset(&r,0,sizeof(r));
    r.tipo = TIPO_DESCONOCIDO;
    if(!e) return r;

    switch(e->tipo){
        case AST_NUMERO: {
            if(strchr(e->valor,'.')){
                size_t L = strlen(e->valor);
                if(L>0 && (e->valor[L-1]=='f'||e->valor[L-1]=='F')){
                    r.tipo = TIPO_FLOAT;
                    r.v.f = strtof(e->valor,NULL);
                } else {
                    r.tipo = TIPO_DOUBLE;
                    r.v.d = strtod(e->valor,NULL);
                }
            } else {
                r.tipo = TIPO_INT;
                r.v.i = atoi(e->valor);
            }
            r.inicializado = 1;
            return r;
        }
        case AST_CADENA: {
            r.tipo = TIPO_STRING;
            r.v.s = e->valor ? strdup(e->valor) : NULL;
            r.inicializado = 1;
            return r;
        }
        case AST_CARACTER: {
            r.tipo = TIPO_CHAR;
            r.v.c = e->valor && *e->valor ? e->valor[0] : '\0';
            r.inicializado = 1;
            return r;
        }
        case AST_BOOLEAN: {
            r.tipo = TIPO_BOOLEAN;
            r.v.b = (e->valor && strcmp(e->valor,"true")==0);
            r.inicializado = 1;
            return r;
        }
        case AST_IDENTIFICADOR: {
            Simbolo* s = buscarSimbolo(e->valor);
            if(s){
                return getValorSimbolo(s);
            }
            return r;
        }
        case AST_OPERACION: {
            if(e->num_hijos!=2) return r;
            ValorSimbolo a = evaluarExpr(e->hijos[0]);
            ValorSimbolo b = evaluarExpr(e->hijos[1]);
            if(!a.inicializado || !b.inicializado || !esNum(a.tipo) || !esNum(b.tipo)) return r;
            // promover a double
            double da = (a.tipo==TIPO_DOUBLE)?a.v.d:(a.tipo==TIPO_FLOAT? a.v.f:(a.tipo==TIPO_INT? a.v.i:(unsigned char)a.v.c));
            double db = (b.tipo==TIPO_DOUBLE)?b.v.d:(b.tipo==TIPO_FLOAT? b.v.f:(b.tipo==TIPO_INT? b.v.i:(unsigned char)b.v.c));
            double res = 0;
            const char* op = e->valor;
            if(strcmp(op,"+")==0) res = da+db;
            else if(strcmp(op,"-")==0) res = da-db;
            else if(strcmp(op,"*")==0) res = da*db;
            else if(strcmp(op,"/")==0) res = db!=0? da/db : 0;
            else if(strcmp(op,"%")==0){
                long ia = (long)da;
                long ib = (long)db;
                res = (ib!=0)? ia % ib : 0;
            }
            // tipo resultante (como deducirTipoExpr)
            TipoDato tr = TIPO_INT;
            if(a.tipo==TIPO_DOUBLE || b.tipo==TIPO_DOUBLE) tr = TIPO_DOUBLE;
            else if(a.tipo==TIPO_FLOAT || b.tipo==TIPO_FLOAT) tr = TIPO_FLOAT;
            else if(a.tipo==TIPO_INT || b.tipo==TIPO_INT) tr = TIPO_INT;
            else tr = TIPO_INT;
            return makeNum(tr,res);
        }
        case AST_CAST: {
            if(e->num_hijos!=1) return r;
            ValorSimbolo orig = evaluarExpr(e->hijos[0]);
            TipoDato destino = obtenerTipoDesdeString(e->valor);
            if(!orig.inicializado) return r;
            if(esNum(destino) && esNum(orig.tipo)){
                double base = 0;
                switch(orig.tipo){
                    case TIPO_DOUBLE: base = orig.v.d; break;
                    case TIPO_FLOAT:  base = orig.v.f; break;
                    case TIPO_INT:    base = orig.v.i; break;
                    case TIPO_CHAR:   base = (unsigned char)orig.v.c; break;
                    default: break;
                }
                return makeNum(destino, base);
            }
            if(destino == orig.tipo) return orig;
            return r;
        }
        default: return r;
    }
}
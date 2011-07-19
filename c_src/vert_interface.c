/* Copyright (c) 2010-2011, Michael Santos <michael.santos@gmail.com>
 * All rights reserved.
 * 
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 * 
 * Redistributions of source code must retain the above copyright
 * notice, this list of conditions and the following disclaimer.
 * 
 * Redistributions in binary form must reproduce the above copyright
 * notice, this list of conditions and the following disclaimer in the
 * documentation and/or other materials provided with the distribution.
 * 
 * Neither the name of the author nor the names of its contributors
 * may be used to endorse or promote products derived from this software
 * without specific prior written permission.
 * 
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
 * "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
 * LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS
 * FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE
 * COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT,
 * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING,
 * BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
 * LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER
 * CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT
 * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN
 * ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
 * POSSIBILITY OF SUCH DAMAGE.
 */
#include "vert.h"
#include "vert_util.h"
#include "vert_interface.h"


/* 0: VERT_RESOURCE, 1: int type 2: int | char* */
    ERL_NIF_TERM
vert_interface_lookup(ErlNifEnv *env, int argc, const ERL_NIF_TERM argv[])
{
    VERT_RESOURCE *vp = NULL;
    int type = VERT_ATTR_NAME;

    VERT_RESOURCE *ifp = NULL;
    ERL_NIF_TERM res = {0};


    VERT_GET_RESOURCE(0, vp, VERT_RES_CONNECT);
    VERT_GET_INT(1, type);

    RESOURCE_ALLOC(ifp, VERT_RES_INTERFACE, vp->res);

    switch (type) {
        case VERT_ATTR_NAME: {
            char name[IFNAMSIZ];

            if (argc != 3)
                return enif_make_badarg(env);

            VERT_GET_STRING(2, name, sizeof(name));

            ifp->res = virInterfaceLookupByName(vp->res, name);
            }
            break;

        case VERT_ATTR_MAC: {
            char mac[18]; /* aa:bb:cc:00:11:22\0 */

            if (argc != 3)
                return enif_make_badarg(env);

            VERT_GET_STRING(2, mac, sizeof(mac));

            ifp->res = virInterfaceLookupByMACString(vp->res, mac);
            }
            break;

        default:
            return error_tuple(env, atom_unsupported);
    }

    if (ifp->res == NULL) {
        enif_release_resource(ifp);
        return verterr(env);
    }

    res = enif_make_resource(env, ifp);
    enif_release_resource(ifp);

    return vert_make_resource(env, atom_domain, res);
}

/* 0: VERT_RESOURCE, 1: int type */
    ERL_NIF_TERM
vert_interface_get(ErlNifEnv *env, int argc, const ERL_NIF_TERM argv[])
{
    VERT_RESOURCE *ifp = NULL;
    int type = VERT_ATTR_NAME;

    const char *res = NULL;


    VERT_GET_RESOURCE(0, ifp, VERT_RES_INTERFACE);
    VERT_GET_INT(1, type);

    switch (type) {
        case VERT_ATTR_NAME:
            res = virInterfaceGetName(ifp->res);
            break;

        case VERT_ATTR_MAC:
            res = virInterfaceGetMACString(ifp->res);
            break;

        case VERT_ATTR_DESC:
            res = virInterfaceGetXMLDesc(ifp->res, 0);
            break;

        case VERT_ATTR_CONNECT: {
            VERT_RESOURCE *cp = NULL;
            ERL_NIF_TERM term = {0};

            RESOURCE_ALLOC(cp, VERT_RES_CONNECT, NULL);
            cp->res = ifp->conn;
            term = enif_make_resource(env, cp);
            enif_release_resource(cp);

            return vert_make_resource(env, atom_connect, term);
            }
            break;

        default:
            return error_tuple(env, atom_unsupported);
    }

    if (res == NULL) {
        enif_release_resource(ifp);
        return verterr(env);
    }

    return enif_make_tuple2(env,
        atom_ok,
        enif_make_string(env, res, ERL_NIF_LATIN1));
}

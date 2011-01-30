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


    ERL_NIF_TERM
verterr(ErlNifEnv *env)
{
    ERL_NIF_TERM res = {0};
    virErrorPtr err = {0};


    err = virSaveLastError();
    res = error_tuple(env, err->message);
    virFreeError(err);

    return res;
}


    ERL_NIF_TERM
error_tuple(ErlNifEnv *env, char *err)
{
    return enif_make_tuple2(env,
            atom_error,
            (err ? enif_make_string(env, err, ERL_NIF_LATIN1) : atom_unsupported));
}  


    ERL_NIF_TERM
bincopy(ErlNifEnv *env, void *src, size_t len)
{
    ErlNifBinary buf = {0};

    if (!enif_alloc_binary(len, &buf))
        return atom_enomem;

    (void)memcpy(buf.data, src, buf.size);

    return enif_make_binary(env, &buf);
}


    void
null_logger(void *userData, virErrorPtr error)
{
}


    void
vert_cleanup(ErlNifEnv *env, void *obj)
{
    VERT_RESOURCE *vp = obj;


    if (vp->res == NULL)
        return;

    switch (vp->type) {
        case VERT_RES_CONNECT:
            (void)virConnectClose(vp->res);
            break;
        case VERT_RES_DOMAIN:
            (void)virDomainFree(vp->res);
            break;
        case VERT_RES_INTERFACE:
            (void)virInterfaceFree(vp->res);
            break;
        case VERT_RES_NETWORK:
            (void)virNetworkFree(vp->res);
            break;
        case VERT_RES_STORAGEPOOL:
            (void)virStoragePoolFree(vp->res);
            break;
#if THIS_VERSION_SUPPORTS_FILTER
        case VERT_RES_FILTER:
            (void)virNWFilterFree(vp->res);
            break;
#endif
        case VERT_RES_SECRET:
            (void)virSecretFree(vp->res);
            break;
        default:
            break;
    }

    vp->res = NULL;
}


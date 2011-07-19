/* Copyright (c) 2011, Michael Santos <michael.santos@gmail.com>
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

ErlNifFunc vert_funcs[] = {
    /* connect */
    {"virConnectOpen", 1, vert_virConnectOpen},
    {"virConnectOpenReadOnly", 1, vert_virConnectOpenReadOnly},
    {"virConnectClose", 1, vert_virConnectClose},
    {"virConnectGetCapabilities", 1, vert_virConnectGetCapabilities},
    {"virConnectGetHostname", 1, vert_virConnectGetHostname},
    {"virConnectGetLibVersion", 1, vert_virConnectGetLibVersion},
    {"virConnectGetMaxVcpus", 2, vert_virConnectGetMaxVcpus},
    {"virNodeGetFreeMemory", 1, vert_virNodeGetFreeMemory},
    {"virNodeGetInfo", 1, vert_virNodeGetInfo},
    {"virNodeGetCellsFreeMemory", 2, vert_virNodeGetCellsFreeMemory},
    {"virConnectGetType", 1, vert_virConnectGetType},
    {"virConnectGetVersion", 1, vert_virConnectGetVersion},
    {"virConnectGetURI", 1, vert_virConnectGetURI},
    {"virConnectIsEncrypted", 1, vert_virConnectIsEncrypted},
    {"virConnectIsSecure", 1, vert_virConnectIsSecure},
    {"virNodeGetSecurityModel", 1, vert_virNodeGetSecurityModel},
    {"virConnectNumOfDomains", 1, vert_virConnectNumOfDomains},
    {"virConnectNumOfInterfaces", 1, vert_virConnectNumOfInterfaces},
    {"virConnectNumOfNetworks", 1, vert_virConnectNumOfNetworks},
    {"virConnectNumOfStoragePools", 1, vert_virConnectNumOfStoragePools},
    {"virConnectNumOfSecrets", 1, vert_virConnectNumOfSecrets},
    {"virConnectNumOfNWFilters", 1, vert_virConnectNumOfNWFilters},
    {"virConnectNumOfDefinedDomains", 1, vert_virConnectNumOfDefinedDomains},
    {"virConnectNumOfDefinedInterfaces", 2, vert_virConnectNumOfDefinedInterfaces},
    {"virConnectNumOfDefinedNetworks", 1, vert_virConnectNumOfDefinedNetworks},
    {"virConnectNumOfDefinedStoragePools", 1, vert_virConnectNumOfDefinedStoragePools},
    {"virConnectListDomains", 2, vert_virConnectListDomains},
    {"virConnectListInterfaces", 2, vert_virConnectListInterfaces},
    {"virConnectListNetworks", 2, vert_virConnectListNetworks},
    {"virConnectListNWFilters", 2, vert_virConnectListNWFilters},
    {"virConnectListSecrets", 2, vert_virConnectListSecrets},
    {"virConnectListStoragePools", 2, vert_virConnectListStoragePools},
    {"virConnectListDefinedDomains", 2, vert_virConnectListDefinedDomains},
    {"virConnectListDefinedInterfaces", 2, vert_virConnectListDefinedInterfaces},
    {"virConnectListDefinedNetworks", 2, vert_virConnectListDefinedNetworks},
    {"virConnectListDefinedStoragePools", 2, vert_virConnectListDefinedStoragePools},

    /* domain */
    {"virDomainCreate", 2, vert_virDomainCreate},
    {"virDomainDefineXML", 2, vert_virDomainDefineXML},
    {"virDomainDestroy", 1, vert_virDomainDestroy},
    {"virDomainGetAutostart", 1, vert_virDomainGetAutostart},
    {"virDomainGetBlockInfo", 2, vert_virDomainGetBlockInfo},
    {"virDomainGetID", 1, vert_virDomainGetID},
    {"virDomainGetInfo", 1, vert_virDomainGetInfo},
    {"virDomainGetJobInfo", 1, vert_virDomainGetJobInfo},
    {"virDomainGetMaxMemory", 1, vert_virDomainGetMaxMemory},
    {"virDomainGetMaxVcpus", 1, vert_virDomainGetMaxVcpus},
    {"virDomainGetMemoryParameters", 1, vert_virDomainGetMemoryParameters},
    {"virDomainGetName", 1, vert_virDomainGetName},
    {"virDomainGetOSType", 1, vert_virDomainGetOSType},
    {"virDomainGetSchedulerParameters", 1, vert_virDomainGetSchedulerParameters},
    {"virDomainGetSchedulerType", 1, vert_virDomainGetSchedulerType},
    {"virDomainGetSecurityLabel", 1, vert_virDomainGetSecurityLabel},
    {"virDomainGetUUID", 1, vert_virDomainGetUUID},
    {"virDomainGetUUIDString", 1, vert_virDomainGetUUIDString},
    {"virDomainGetXMLDesc", 2, vert_virDomainGetXMLDesc},
    {"virDomainLookupByID", 2, vert_virDomainLookupByID},
    {"virDomainLookupByName", 2, vert_virDomainLookupByName},
    {"virDomainLookupByUUID", 2, vert_virDomainLookupByUUID},
    {"virDomainRestore", 2, vert_virDomainRestore},
    {"virDomainResume", 1, vert_virDomainResume},
    {"virDomainSave", 2, vert_virDomainSave},
    {"virDomainSetAutostart", 2, vert_virDomainSetAutostart},
    {"virDomainShutdown", 1, vert_virDomainShutdown},
    {"virDomainSuspend", 1, vert_virDomainSuspend},
    {"virDomainUndefine", 1, vert_virDomainUndefine},

    /* interface */
    {"virInterfaceCreate", 1, vert_virInterfaceCreate},
    {"virInterfaceDefineXML", 2, vert_virInterfaceDefineXML},
    {"virInterfaceDestroy", 1, vert_virInterfaceDestroy},
    {"virInterfaceGetMACString", 1, vert_virInterfaceGetMACString},
    {"virInterfaceGetName", 1, vert_virInterfaceGetName},
    {"virInterfaceGetXMLDesc", 1, vert_virInterfaceGetXMLDesc},
    {"virInterfaceLookupByMACString", 2, vert_virInterfaceLookupByMACString},
    {"virInterfaceLookupByName", 2, vert_virInterfaceLookupByName},
    {"virInterfaceUndefine", 1, vert_virInterfaceUndefine},

    /* network */
    {"virNetworkCreate", 1, vert_virNetworkCreate},
    {"virNetworkDefineXML", 2, vert_virNetworkDefineXML},
    {"virNetworkDestroy", 1, vert_virNetworkDestroy},
    {"virNetworkGetAutostart", 1, vert_virNetworkGetAutostart},
    {"virNetworkGetAutostart", 1, vert_virNetworkGetAutostart},
    {"virNetworkGetBridgeName", 1, vert_virNetworkGetBridgeName},
    {"virNetworkGetName", 1, vert_virNetworkGetName},
    {"virNetworkGetUUID", 1, vert_virNetworkGetUUID},
    {"virNetworkGetXMLDesc", 2, vert_virNetworkGetXMLDesc},
    {"virNetworkIsPersistent", 1, vert_virNetworkIsPersistent},
    {"virNetworkLookupByName", 2, vert_virNetworkLookupByName},
    {"virNetworkLookupByUUID", 2, vert_virNetworkLookupByUUID},
    {"virNetworkLookupByUUIDString", 2, vert_virNetworkLookupByUUIDString},
    {"virNetworkUndefine", 1, vert_virNetworkUndefine},

    {NULL, 0, NULL}
};
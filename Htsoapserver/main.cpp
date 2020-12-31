#include <iostream>
#include "soapH.h"
#include "HTSAPServerSoapBinding.nsmap"
#include <windows.h>
#include <tchar.h>

using namespace std;

int __ns1__login(struct soap*, ns1__login *ns1__login_, ns1__loginResponse &ns1__loginResponse_)
{
    printf("Client is login\n");
    char str[100];
    DWORD processId = GetCurrentProcessId();
    DWORD sessionId;
    ProcessIdToSessionId(processId, &sessionId);
    if (ns1__login_->strDeviceId.c_str() != "" && ns1__login_->strDeviceKey.c_str() != "")
    {
        sprintf(str,"0000^%u",sessionId);
        std::string *pStr = new std::string(str);
        ns1__loginResponse_.return_ = pStr;
    }
    return SOAP_OK;
}

int  __ns1__logout(struct soap*, ns1__logout *ns1__logout_, ns1__logoutResponse &ns1__logoutResponse_)
{
    printf("Client id lgout\n");
    if (ns1__logout_->sid.c_str() != "")
    {
        std::string *pStr = new std::string("0000");
        ns1__logoutResponse_.return_ = pStr;
    }
    return SOAP_OK;
}

int  __ns1__NSyncWriteMobileEPVInfo(struct soap*, ns1__NSyncWriteMobileEPVInfo *ns1__NSyncWriteMobileEPVInfo_, ns1__NSyncWriteMobileEPVInfoResponse &ns1__NSyncWriteMobileEPVInfoResponse_)
{
    return SOAP_OK;
}

int  __ns1__syncWriteVehicleInfo(struct soap*, ns1__syncWriteVehicleInfo *ns1__syncWriteVehicleInfo_, ns1__syncWriteVehicleInfoResponse &ns1__syncWriteVehicleInfoResponse_)
{
    return SOAP_OK;
}

int  __ns1__writeVehicleInfo(struct soap*, ns1__writeVehicleInfo *ns1__writeVehicleInfo_, ns1__writeVehicleInfoResponse &ns1__writeVehicleInfoResponse_)
{
    return SOAP_OK;
}

int __ns1__queryLimitSpeed(struct soap*, ns1__queryLimitSpeed *ns1__queryLimitSpeed_, ns1__queryLimitSpeedResponse &ns1__queryLimitSpeedResponse_)
{
    return SOAP_OK;
}

int  __ns1__queryViolateSpeed(struct soap*, ns1__queryViolateSpeed *ns1__queryViolateSpeed_, ns1__queryViolateSpeedResponse &ns1__queryViolateSpeedResponse_)
{
    return SOAP_OK;
}

int  __ns1__querySyncTime(struct soap*, ns1__querySyncTime *ns1__querySyncTime_, ns1__querySyncTimeResponse &ns1__querySyncTimeResponse_)
{
    return SOAP_OK;
}

int  __ns1__writeAlarmInfo(struct soap*, ns1__writeAlarmInfo *ns1__writeAlarmInfo_, ns1__writeAlarmInfoResponse &ns1__writeAlarmInfoResponse_)
{
    return SOAP_OK;
}
int __ns1__NWriteVehicleInfo(struct soap*, ns1__NWriteVehicleInfo *ns1__NWriteVehicleInfo_, ns1__NWriteVehicleInfoResponse &ns1__NWriteVehicleInfoResponse_)
{
    return SOAP_OK;
}

int __ns1__NWriteVehicleInfoEx(struct soap*, ns1__NWriteVehicleInfoEx *ns1__NWriteVehicleInfoEx_, ns1__NWriteVehicleInfoExResponse &ns1__NWriteVehicleInfoExResponse_)
{
    return SOAP_OK;
}

int __ns1__NSyncWriteVehicleInfo(struct soap*, ns1__NSyncWriteVehicleInfo *ns1__NSyncWriteVehicleInfo_, ns1__NSyncWriteVehicleInfoResponse &ns1__NSyncWriteVehicleInfoResponse_)
{
    return SOAP_OK;
}

int __ns1__WriteFlux(struct soap*, ns1__WriteFlux *ns1__WriteFlux_, ns1__WriteFluxResponse &ns1__WriteFluxResponse_)
{
    return SOAP_OK;
}

int __ns1__NWriteDeviceStatus(struct soap*, ns1__NWriteDeviceStatus *ns1__NWriteDeviceStatus_, ns1__NWriteDeviceStatusResponse &ns1__NWriteDeviceStatusResponse_)
{
    return SOAP_OK;
}

int __ns1__NSyncWriteVioInfo(struct soap*, ns1__NSyncWriteVioInfo *ns1__NSyncWriteVioInfo_, ns1__NSyncWriteVioInfoResponse &ns1__NSyncWriteVioInfoResponse_)
{
    printf("Client is send IllegeInfo\n");
    char str[100];
    if (ns1__NSyncWriteVioInfo_->sid != "" && ns1__NSyncWriteVioInfo_->strDeviceId != "" && ns1__NSyncWriteVioInfo_->strDirectionId != "" && ns1__NSyncWriteVioInfo_->strVehicleId != "")
    {
        std::string *pStr = new std::string("0000");
        ns1__NSyncWriteVioInfoResponse_.return_ = pStr;
    }
    return SOAP_OK;
}

int __ns1__NWritePassStat(struct soap*, ns1__NWritePassStat *ns1__NWritePassStat_, ns1__NWritePassStatResponse &ns1__NWritePassStatResponse_)
{
    return SOAP_OK;
}

int __ns1__SyncWriteVehPassInfo(struct soap*, ns1__SyncWriteVehPassInfo *ns1__SyncWriteVehPassInfo_, ns1__SyncWriteVehPassInfoResponse &ns1__SyncWriteVehPassInfoResponse_)
{
    printf("Client is send VehPassInfo\n");
    if (ns1__SyncWriteVehPassInfo_->sid != "" && ns1__SyncWriteVehPassInfo_->xmlParam != "")
    {
        std::string *pStr = new std::string("0000");
        ns1__SyncWriteVehPassInfoResponse_.return_ = pStr;
    }
    return SOAP_OK;
}

int __ns1__WriteVehPassInfo(struct soap*, ns1__WriteVehPassInfo *ns1__WriteVehPassInfo_, ns1__WriteVehPassInfoResponse &ns1__WriteVehPassInfoResponse_)
{
    return SOAP_OK;
}

int __ns1__SyncWriteAreaSpeed(struct soap*, ns1__SyncWriteAreaSpeed *ns1__SyncWriteAreaSpeed_, ns1__SyncWriteAreaSpeedResponse &ns1__SyncWriteAreaSpeedResponse_)
{
    return SOAP_OK;
}

int __ns1__WriteAreaSpeed(struct soap*, ns1__WriteAreaSpeed *ns1__WriteAreaSpeed_, ns1__WriteAreaSpeedResponse &ns1__WriteAreaSpeedResponse_)
{
    return SOAP_OK;
}

int main()
{
    struct soap *serversoap = soap_new();
    int socket_master = soap_bind(serversoap, NULL, 7081, 100);
    if (socket_master < 0)
    {
        soap_print_fault(serversoap, stderr);
        exit(-1);
    }
    printf("SoapBind success,the master socket number is:%d\n", socket_master);
   
    while (1)
    {
        int socket_listen = soap_accept(serversoap);
        if (socket_listen < 0)
        {
            soap_print_fault(serversoap, stderr);
            exit(-2);
        }
        printf("Get a new connection,the slaver socket number is:%d\n", socket_listen); //绑定成功返回监听套接字
        soap_serve(serversoap);
        soap_end(serversoap);
    }
    soap_done(serversoap);
    free(serversoap);
    return 0;
}

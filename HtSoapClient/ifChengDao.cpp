#include "soapH.h"
#include "ifChengDao.h"
#include "HTSAPServerSoapBinding.nsmap"

static void ExpDataWrite(char *fileName, char *pInfo)
{
	FILE* fp1 = fopen(fileName, "ab+");
	if (fp1 == NULL)
	{
		return;
	}
	fprintf(fp1, "%s\n", pInfo);
	fclose(fp1);
}

API int ifChengDao__login(char *soap_endpoint, char *pDeviceId, char *pDeviceKey, char *szSidOut)
{
	int nRet = 0;
	struct soap g_tsoap;
	ns1__login *ptLogin = soap_new_set_ns1__login(&g_tsoap, pDeviceId, pDeviceKey);

	ns1__loginResponse loginResponse;
	nRet = soap_call___ns1__login(&g_tsoap, soap_endpoint, NULL, ptLogin, loginResponse);
	if (nRet != SOAP_OK)
	{
		printf("Error while calling the soap_call___ns1__login\n");
	}
	else
	{
		printf("Calling the soap_call___ns1__login success¡£\n");
	}
	if (loginResponse.return_)
	{
		sprintf(szSidOut, "%s", loginResponse.return_->c_str());
	}
	soap_end(&g_tsoap);
	soap_destroy(&g_tsoap);
	soap_done(&g_tsoap);

	return nRet;
}


API int ifChengDao__logout(char *soap_endpoint, char *sId)
{
	int nRet = 0;
	struct soap g_tsoap;
	ns1__logout *pLogout = soap_new_set_ns1__logout(&g_tsoap, sId);
	ns1__logoutResponse logoutResponse;
	nRet = soap_call___ns1__logout(&g_tsoap, soap_endpoint, NULL, pLogout, logoutResponse);
	if (nRet != SOAP_OK)
	{
		printf("Error while calling the soap_call___ns1__logout\n");
	}
	else
	{
		printf("Calling the soap_call___ns1__logout success¡£\n");
	}

	soap_end(&g_tsoap);
	soap_destroy(&g_tsoap);
	soap_done(&g_tsoap);

	return nRet;
}


API int ifChengDao__setIllegalVehInfo(char *soap_endpoint, TChengDao_VioInfo *ptData)
{
	int nRet = 0;
	struct soap g_tsoap;
	xsd__base64Binary *tplj1 = new xsd__base64Binary();
	tplj1->__size = ptData->__size1;
	tplj1->__ptr = ptData->__ptr1;
	xsd__base64Binary *tplj2 = new xsd__base64Binary();
	tplj2->__size = ptData->__size2;
	tplj2->__ptr = ptData->__ptr2;
	xsd__base64Binary *tplj3 = new xsd__base64Binary();
	tplj3->__size = ptData->__size3;
	tplj3->__ptr = ptData->__ptr3;
	xsd__base64Binary *tplj4 = new xsd__base64Binary();
	tplj4->__size = ptData->__size4;
	tplj4->__ptr = ptData->__ptr4;
	xsd__base64Binary *tplj5 = new xsd__base64Binary();
	tplj5->__size = ptData->__size5;
	tplj5->__ptr = ptData->__ptr5;
	xsd__base64Binary *tplj6 = new xsd__base64Binary();
	tplj6->__size = ptData->__size6;
	tplj6->__ptr = ptData->__ptr6;
	xsd__base64Binary *tplj7 = new xsd__base64Binary();
	tplj7->__size = ptData->__sizeVideo;
	tplj7->__ptr = ptData->__ptrVideo;
	ns1__NSyncWriteVioInfo *pIllegalData = soap_new_set_ns1__NSyncWriteVioInfo(&g_tsoap, ptData->sid,
		ptData->pDeviceId, ptData->pVehicleId, ptData->pDeviceType, ptData->pDirectionId, ptData->pDriveWayId
		, ptData->pPlateNum, ptData->pPlateType, ptData->pPassTime, ptData->pRedStartTime, ptData->pRedLastTime
		, ptData->nSpeed, ptData->nLargeLimitSpeed, ptData->nMinLimitSpeed, ptData->pIllegalType, ptData->pIllegalType2
		, ptData->nCarLen, ptData->pPlateColor, ptData->pVehType, *tplj1, *tplj2
		,*tplj3,*tplj4,*tplj5,*tplj6,*tplj7, ptData->__pRemoteData, ptData->pViolate, ptData->pSendType
		, ptData->pPlaceId, ptData->pPlaceName, "0", "", 0, 0, ptData->pCarColor, "", "", "", ptData->pReseve1, ptData->pReseve2, ptData->pReseve3);

	ns1__NSyncWriteVioInfoResponse tVioInfoResp;
	nRet = soap_call___ns1__NSyncWriteVioInfo(&g_tsoap, soap_endpoint, NULL, pIllegalData, tVioInfoResp);
	if (nRet != SOAP_OK)
	{
		printf("Error while calling the soap_call___ns1__NSyncWriteVioInfo\n");
	}
	else
	{
		printf("Calling the soap_new_set_ns1__NSyncWriteVioInfo success\n");
	}
	if (tVioInfoResp.return_)
	{
		printf("soap_new_set_ns1__NSyncWriteVioInfo Response:%s\n", tVioInfoResp.return_->c_str());
		char tmpBuf[5] = { 0 };
		memcpy(tmpBuf, tVioInfoResp.return_->c_str(), 4);
		if (strcmp(tmpBuf, "0000") != 0)
		{
			printf("Calling the soap_new_set_ns1__NSyncWriteVioInfo failed\n");
		}
	}

	delete tplj1;
	delete tplj2;
	delete tplj3;
	delete tplj4;
	delete tplj5;
	delete tplj6;
	delete tplj7;

	soap_end(&g_tsoap);
	soap_destroy(&g_tsoap);
	soap_done(&g_tsoap);

	return nRet;
}


API int ifChengDao__setPassVehInfo(char *soap_endpoint, TChengDao_VehPassInfo *ptData)
{
	int nRet = 0;
	struct soap g_tsoap;
	xsd__base64Binary *tplj1 = new xsd__base64Binary();
	tplj1->__size = ptData->__size1;
	tplj1->__ptr = ptData->__ptr1;
	xsd__base64Binary *tplj2 = new xsd__base64Binary();
	tplj2->__size = ptData->__size2;
	tplj2->__ptr = ptData->__ptr2;
	xsd__base64Binary *tplj3 = new xsd__base64Binary();
	tplj3->__size = ptData->__size3;
	tplj3->__ptr = ptData->__ptr3;
	xsd__base64Binary *tplj4 = new xsd__base64Binary();
	tplj4->__size = ptData->__size4;
	tplj4->__ptr = ptData->__ptr4;
	xsd__base64Binary *tplj5 = new xsd__base64Binary();
	tplj5->__size = ptData->__size5;
	tplj5->__ptr = ptData->__ptr5;
	xsd__base64Binary *tplj6 = new xsd__base64Binary();
	tplj6->__size = ptData->__size6;
	tplj6->__ptr = ptData->__ptr6;
	xsd__base64Binary *tplj7 = new xsd__base64Binary();
	tplj7->__size = ptData->__sizeVideo;
	tplj7->__ptr = ptData->__ptrVideo;

	ExpDataWrite((char*)"/usr/log/soInfo.txt", (char*)"soap_new_set_ns1__SyncWriteVehPassInfo start");

	ns1__SyncWriteVehPassInfo *pVehInfo = soap_new_set_ns1__SyncWriteVehPassInfo(&g_tsoap, ptData->pSid, ptData->pXmlData, *tplj1
		, *tplj2, *tplj3,*tplj4,* tplj5, *tplj6, *tplj7);

	ExpDataWrite((char*)"/usr/log/soInfo.txt", (char*)"soap_new_set_ns1__SyncWriteVehPassInfo ---------222---");

	ns1__SyncWriteVehPassInfoResponse vehPassInfoRsp;
	nRet = soap_call___ns1__SyncWriteVehPassInfo(&g_tsoap, soap_endpoint, NULL, pVehInfo, vehPassInfoRsp);

	ExpDataWrite((char*)"/usr/log/soInfo.txt", ( char*)"soap_new_set_ns1__SyncWriteVehPassInfo ---------3333---");
	if (nRet != SOAP_OK)
	{
		printf("Error while calling the soap_new_set_ns1__SyncWriteVehPassInfo\n");
	}
	else
	{
		printf("Calling the soap_new_set_ns1__SyncWriteVehPassInfo success\n");
	}
	if (vehPassInfoRsp.return_)
	{
		ExpDataWrite((char*)"/usr/log/soInfo.txt", (char*)"soap_new_set_ns1__SyncWriteVehPassInfo ---------4444---");
		printf("soap_new_set_ns1__SyncWriteVehPassInfo Response:%s\n", vehPassInfoRsp.return_->c_str());
		char tmpBuf[5] = { 0 };

		ExpDataWrite((char*)"/usr/log/soInfo.txt", (char*)"soap_new_set_ns1__SyncWriteVehPassInfo ---------5555---");
		memcpy(tmpBuf, vehPassInfoRsp.return_->c_str(), 4);
		if (strcmp(tmpBuf, "0000") != 0)
		{
			printf("Calling the soap_new_set_ns1__NSyncWriteVioInfo failed\n");
		}

	}
	
	ExpDataWrite((char*)"/usr/log/soInfo.txt", (char*)"soap_new_set_ns1__SyncWriteVehPassInfo ---------6666---");

	delete tplj1;
	delete tplj2;
	delete tplj3;
	delete tplj4;
	delete tplj5;
	delete tplj6;
	delete tplj7;

	soap_end(&g_tsoap);
	soap_destroy(&g_tsoap);
	soap_done(&g_tsoap);

	return nRet;
}


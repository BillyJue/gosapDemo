#include <iostream>
#include "ifChengDao.h"
using namespace std;
#include <windows.h>
char* textFileRead(char* filename, long *pSize)
{
	char* text;
	FILE *pf = fopen(filename, "r");
	fseek(pf, 0, SEEK_END);
	long lSize = ftell(pf);
	// 用完后需要将内存free掉
	text = (char*)malloc(lSize + 1);
	*pSize = lSize;
	rewind(pf);
	fread(text, sizeof(char), lSize, pf);
	text[lSize] = '\0';
	return text;
}

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
int main()
{
	char pRequset[256] = { "http://10.73.0.186:7081/HTServer/services/HTSAPServer" };
	char sId[64];
	int nRet = ifChengDao__login(pRequset, "123456789", "0000000", sId);

	TChengDao_VioInfo info;
	memset(&info, 0, sizeof(TChengDao_VioInfo));
	info.pPlaceId = "32";
	info.sid = sId;
	info.pDeviceId = "1232";
	info.pVehicleId = "1";
	info.pDeviceType = "11";
	info.pDirectionId = "A";
	info.pDriveWayId = "1";
	info.pPlateNum = "aaE1234";
	info.pPlateType = "3";
	info.pPassTime = "20201118";
	info.pRedStartTime = "2011012312";
	info.pRedLastTime = "30";
	info.nSpeed = 20;
	info.nLargeLimitSpeed = 100;
	info.nMinLimitSpeed = 20;
	info.pIllegalType = "32";
	info.pIllegalType2 = "";
	info.nCarLen = 0;
	info.pPlateColor = "F";
	info.__pRemoteData = "3";
	info.pViolate = "0";
	info.pSendType = "0";
	info.pPlaceName = "32434";
	info.pCarColor = "22w";
	info.pVehType = "3";
	info.pReseve1 = "";
	info.pReseve2 = "";
	info.pReseve3 = "";

	ExpDataWrite("2.txt", "324423");
	ExpDataWrite("2.txt", "11111");
	//nRet = ifChengDao__setIllegalVehInfo(pRequset, &info);

	TChengDao_VehPassInfo tInfo;
	memset(&tInfo, 0, sizeof(TChengDao_VehPassInfo));
	tInfo.pSid = sId;
	tInfo.pXmlData = "<root><sbbh>123456789</sbbh><fxbh>00</fxbh><hphm>未识别</hphm><hpzl>99</hpzl><clbh>1</clbh><gcsj>2020-11-18 17:53:07.742</gcsj><clsd>0</clsd><cwkc>0</cwkc><hpys>4</hpys><cllx>2</cllx><hdlqsj>1970-01-01 00:00:00</hdlqsj><hdcxsj>0</hdcxsj><wfxw> </wfxw><wfxw2></wfxw2><dcxs>0</dcxs><dcdxs>0</dcdxs><xcxs>0</xcxs><xcdxs>0</xcdxs><wfbj>0</wfbj><cdbh>1</cdbh><ddbh></ddbh><ddms> </ddms><clpp>0</clpp><clzpp> </clzpp><csys>Z</csys><csyssd></csyssd><zjaqd>0</zjaqd><zjzyb>0</zjzyb><fjaqd>0</fjaqd><fjzyb>0</fjzyb><clxh> </clxh><jtnk> </jtnk><zpfx> </zpfx></root>";
	long size;
	char *pFile = textFileRead("vehPass.log", &size);
	//tInfo.__ptr1 = (unsigned char *)pFile;
	//tInfo.__size1 = size;

	string sTemp = "12345";
	tInfo.__ptr1 = (unsigned char *)sTemp.c_str();
	tInfo.__size1 = 5;

	for (int i = 0; i < 10; i++)
	{
		nRet = ifChengDao__setPassVehInfo(pRequset, &tInfo);
		Sleep(1000);
	}
	

	nRet = ifChengDao__logout(pRequset, sId);

	return 0;
}
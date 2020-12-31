#ifndef ifChengDao_h__
#define ifChengDao_h__

#include <stdio.h>
#include <string>

//违法图片
typedef struct
{
	/*login返回的sid*/
	char *sid;
	/*设备编号*/
	char *pDeviceId;
	/*车辆编号*/
	char *pVehicleId;
	/*设备类型*/
	char *pDeviceType;
	/*方向编号*/
	char *pDirectionId;
	/*车道编号*/
	char *pDriveWayId;
	/*号牌号码*/
	char *pPlateNum;
	/*号牌类型*/
	char *pPlateType;
	/*经过时间*/
	char *pPassTime;
	/*红灯开始时间*/
	char *pRedStartTime;
	/*红灯持续时间*/
	char *pRedLastTime;
	/*车辆速度*/
	long nSpeed;
	/*大车限速*/
	long nLargeLimitSpeed;
	/*小车限速*/
	long nMinLimitSpeed;
	/*违章行为编码*/
	char *pIllegalType;
	/*可空*/
	char *pIllegalType2;
	/*车长 以厘米为单位 可空*/
	long nCarLen;
	/*号牌颜色*/
	char *pPlateColor;
	/*车辆类型*/
	char *pVehType;
	/*图片1 二进制*/
	unsigned char *__ptr1;
    int   __size1;

	/*图片2 二进制*/
	unsigned char *__ptr2;
    int   __size2;

	/*图片1 二进制*/
	unsigned char *__ptr3;
    int   __size3;

	/*图片1 二进制*/
	unsigned char *__ptr4;
    int   __size4;

	/*图片5 人像图片 二进制*/
	unsigned char *__ptr5;
    int   __size5;

	/*图片6 号牌特写 二进制*/
	unsigned char *__ptr6;
    int   __size6;

	/*视频 二进制*/
	unsigned char *__ptrVideo;
    int   __sizeVideo;

	/*图片远程访问路径 可空*/
	char *__pRemoteData;
	/*违法标记 0普通记录  1违法记录非空*/
	char *pViolate;
    /*发送标志 "0"代表正常  "1"代表滞后发送 非空*/
	char *pSendType;
	/*违法地点编码*/
	char *pPlaceId;
	/*违法地点名称*/
	char *pPlaceName;
	/*车身颜色*/
	char *pCarColor;
    /*车身深度*/
    
	/*保留字段1*/
	char *pReseve1;
	/*保留字段2*/
	char *pReseve2;
	/*保留字段3*/
	char *pReseve3;
}TChengDao_VioInfo;

typedef struct
{
	/*login返回的sid*/
	char *pSid;
	/*过车信息项*/
	char *pXmlData;
	/*图片1 车辆全景图 二进制*/
	unsigned char *__ptr1;
    int   __size1;
	/*图片2 全景图片 二进制*/
	unsigned char *__ptr2;
    int   __size2;
	/*图片3 全景图片2 二进制*/
	unsigned char *__ptr3;
    int   __size3;    
	/*图片4 备用 二进制*/
	unsigned char *__ptr4;
    int   __size4;
	/*图片5 人像图片 二进制*/
	unsigned char *__ptr5;
    int   __size5;
	/*图片6 号牌特写 二进制*/
	unsigned char *__ptr6;
    int   __size6;

	/*视频 二进制*/
	unsigned char *__ptrVideo;
    int   __sizeVideo;

}TChengDao_VehPassInfo;

#ifdef __cplusplus
extern "C" {
#endif

#ifndef API
#ifdef _MSC_VER
#define API   __declspec(dllexport)
#else
#define API
#endif
#endif

    API int ifChengDao__login(char *soap_endpoint, char *pDeviceId, char *pDeviceKey, char *szSidOut);

    API int ifChengDao__logout(char *soap_endpoint, char *sId);


	API int ifChengDao__setIllegalVehInfo(char *soap_endpoint, TChengDao_VioInfo *ptData);

	API int ifChengDao__setPassVehInfo(char *soap_endpoint, TChengDao_VehPassInfo *ptData);

#ifdef __cplusplus
}
#endif

#endif // ifChengDao_h__

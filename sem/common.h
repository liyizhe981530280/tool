/** 
 * @file common.h 
 * @brief common function  
 * @date  2/28/2017 
 * @author huang 
 */
#ifndef _COMMON_H_H
#define _COMMON_H_H

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>

#include <pthread.h>
#define VOICE_DEV_VERSION  "V1.03.000"
#if UH_UNISIOT
#define SERVER_IP "uh.unisiot.com"
#define WEB_IP "uhp.unisiot.com"
#elif TEST_UNISIOT
#define SERVER_IP "test.unisiot.com"
#define WEB_IP "test.unisiot.com"
#else 
#define SERVER_IP "chkshcs.unisiot.com"
#define WEB_IP "chk.unisiot.com"
#endif



enum RET_ARGS
{
    SUCCESS = 0,
    FAIL = -1,
    INVALID_ARGS = -2,
    NOT_FOUND = -3,
    EMPTY = -4,
};

enum CMD_TYPE
{
    TTS_CMD = 0,
    MUSIC_CMD_START = 1,
    MUSIC_CMD_PLAY = 2,
    MUSIC_CMD_PAUSE = 2,
    MUSIC_CMD_USER_PAUSE = 4,
    MUSIC_CMD_USER_PLAY = 5,
    MUSIC_CMD_USER_STOP = 6,
    MUSIC_CMD_USER_PAUSE_EX = 7,
    MUSIC_CMD_USER_NEXT = 8,
    MUSIC_CMD_USER_LAST = 9
};

enum DEV_TYPE
{
    SINGLE_FIRE_SWITCH = 0X01,  //单火开关
    ZERO_FIRE_SWITCH = 0X02,   //零火开关
    DIMMING_SWITCH = 0X03,     //调光开关
    CURTAIN = 0X04,            //窗帘
    MACHINE_SWITCH = 0x07,     // 机械开关
    LED_RGB = 0X08,            //LED RGB灯
    OUTLET = 0X11,             //插座
    POWER_CONSUM_OUTLET = 0X12, //功耗插座
    POWER_STRIP = 0X13,        //插排
    ENV_PROBES = 0X21,         //环境探头
    SEC_PROBES = 0X31,         //安防探头
    REPEATERS = 0x41,          // 红外转发器
    PROTOCOL_CON = 0X42,       //协议转换器
    THERMOSTAT = 0X61,         //温控器
    OPEN_WINDOW = 0X43,        // 开窗器
    SCENE_PANEL = 0X51,        //场景面板
    LOCK = 0X71,               //门锁类
    PHY_HEALTH = 0X72,         //生理健康类
    AIR_PUR = 0X73,            //空气净化器类
    IRRIGATION_DEV = 0x79,     //灌溉设备  2016/7/15 add
    BG_MUSIC = 0x81,           //背景音乐
    CAMERA = 0X82,             //摄像头
    AMPLIFIER = 0X83,          //功放
    CAMERA_EX = 0x84,          //投影机
    AIR_CONDITIONER = 0x89,    //空调
    ADA_DOOR_LOCK = 0x8B,      //门锁
    RED_TV = 0X91,            //红外电视
    RED_AIR = 0X92,           //红外空调
    RED_CURTAIN = 0X93,       //红外窗帘
    RED_HANGER = 0X94,        //红外吊架
    RED_PLAYER = 0X95,        //红外高清播放机
    RED_DVD = 0X96,           //红外DVD
    RED_STB = 0X97,           //红外机顶盒
    RED_PREJECTOR = 0X98,     //红外投影仪
    RED_POWER = 0X99,         //红外功放
    RED_PUR = 0X9A,          //红外空气净化器
    RED_PRE1 = 0X9B,          //红外预留1
    RED_PRE2 = 0X9C,          //红外预留2
    RED_PRE3 = 0X9D,          //红外预留3
    RED_PRE4 = 0X9E,          //红外预留4
    RED_PRE5 = 0X9F,          //红外预留5
    REPEATER_EX = 0XA0,       //中继器 11/5/2016 add
    ALARM_SERVICE = 0XA1,     //报警服务 11/23/2016 add

};

//二次交互使用
struct inter_info_second{
    char dev_name[2][128];
    int session;
};
struct st_cmd {
    int cmd;
    int pre;
    int ota;  //OTA还是普通升级标志 3/30/2018 add
    char pre_str[32];
    char sp_buf[5][64]; //存放一些额外参数 7/24/2017 add
    char buf[1024*10];
    int numbersong; // 歌曲的编号
};

#endif

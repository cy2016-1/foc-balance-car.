#include <Arduino.h>

/********************************
设置命令格式
设置速度: M0 V5
设置转向: M0 T5
设置速度PID: M0 PVP0.01/I0.01/D0.01
设置直立PID: M0 PSP0.01/I0.01/D0.01
设置转向PID: M0 PTP0.01/I0.01/D0.01
保存PID数据: M0 SP
重置PID数据: M0 RP

查询命令格式
查询PID    : M0 UP
查询陀螺仪  : M0 UG
查询速度    : M0 UV
查询转向    : M0 UT

查询数据格式
上传PID    : P 0 0 0 0 0 0 0 0 0 (三个一组，分别对应速度，直立，转向PID)
上传陀螺仪  : G 0 0 0 0 0 0 (对应roll pitch yaw x_gyro y_gyro z_gyro)
上传速度   : V 0
上传转向   : T 0
*********************************/
enum{
  COMMAND_TYPE_NONE,
  COMMAND_TYPE_SET,
  COMMAND_TYPE_QUERY,
};

void replaceChar(String &str, char find, char replace) {
  for (int i = 0; i < str.length(); i++) {
    if (str.charAt(i) == find) {
      str.setCharAt(i, replace);
    }
  }
}

//接收的字符串用_分隔，替换成空格然后发送至串口
String command_process(int type, char *buf){
  String query_result = "";
  
  if(type == COMMAND_TYPE_NONE || (strlen(buf) == 0))
    return query_result;

  String cmd = String(buf);
  replaceChar(cmd, '_', ' ');
  Serial.println(cmd);

  if(type == COMMAND_TYPE_SET)
  {
    //设置命令
  }
  else if(type == COMMAND_TYPE_QUERY)
  {
    //查询命令
    while(true)
    {
      if(Serial.available())
      {
        query_result = Serial.readStringUntil('\n');
        break;
      }
      delay(200);
    }
  }

  return query_result;
}

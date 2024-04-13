#include "sys_config.h"
#include "user_config.h"
#include "user_inc.h"
#include "macro.h"

sys_config_t sys_config_data;
uint32_t dev_id;

static inline void chip_id_read()
{
	dev_id = HAL_GetDEVID();
}

static void sys_default_init()
{
	sys_config_data.dev_id[0] = (dev_id >> 24) & 0xff;
	sys_config_data.dev_id[1] = (dev_id >> 16) & 0xff;
	sys_config_data.dev_id[2] = (dev_id >> 8 ) & 0xff;
	sys_config_data.dev_id[3] =  dev_id        & 0xff;	
	
	sys_config_data.pid_vel[0] = DEF_PID_VEL_P;
	sys_config_data.pid_vel[1] = DEF_PID_VEL_I;
	sys_config_data.pid_vel[2] = DEF_PID_VEL_D;
	
	sys_config_data.pid_stand[0] = DEF_PID_STAND_P;
	sys_config_data.pid_stand[1] = DEF_PID_STAND_I;
	sys_config_data.pid_stand[2] = DEF_PID_STAND_D;
	
	sys_config_data.pid_turn[0] = DEF_PID_TURN_P;
	sys_config_data.pid_turn[1] = DEF_PID_TURN_I;
	sys_config_data.pid_turn[2] = DEF_PID_TURN_D;
	
	//写入flash
	sys_config_write();
}

void sys_config_init()
{
	memset(&sys_config_data, 0x0, sizeof(sys_config_t));
	
	chip_id_read();
	sys_config_read();
	
	DEBUG_P("chipID, readID: 0x%08x, 0x%08x\n", dev_id, BYTES_TO_U32(sys_config_data.dev_id[0], sys_config_data.dev_id[1], sys_config_data.dev_id[2], sys_config_data.dev_id[3]));
	
	if(dev_id == BYTES_TO_U32(sys_config_data.dev_id[0], sys_config_data.dev_id[1], sys_config_data.dev_id[2], sys_config_data.dev_id[3]))
	{
		//设备ID相同,读取配置正确
		DEBUG_P("sys config read ok!\n");
	}
	else
	{
		DEBUG_P("sys config read error!\n");
		//设备ID不同，配置初始化
	}
}

void sys_config_read()
{
	//读取配置
	
}

void sys_config_write()
{
	//存储配置
	
}

void sys_config_reset()
{
	sys_default_init();
}








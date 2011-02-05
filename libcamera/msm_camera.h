/* Copyright (c) 2009, Code Aurora Forum. All rights reserved.
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License version 2 and
 * only version 2 as published by the Free Software Foundation.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA
 * 02110-1301, USA.
 *
 */

#ifndef __LINUX_MSM_CAMERA_H
#define __LINUX_MSM_CAMERA_H

#include <linux/types.h>
#include <asm/sizes.h>
#include <linux/ioctl.h>

#define MSM_CAM_IOCTL_MAGIC 'm'

#define MSM_CAM_IOCTL_GET_SENSOR_INFO \
	_IOR(MSM_CAM_IOCTL_MAGIC, 1, struct msm_camsensor_info *)

#define MSM_CAM_IOCTL_REGISTER_PMEM \
	_IOW(MSM_CAM_IOCTL_MAGIC, 2, struct msm_pmem_info *)

#define MSM_CAM_IOCTL_UNREGISTER_PMEM \
	_IOW(MSM_CAM_IOCTL_MAGIC, 3, unsigned)

#define MSM_CAM_IOCTL_CTRL_COMMAND \
	_IOW(MSM_CAM_IOCTL_MAGIC, 4, struct msm_ctrl_cmd *)

#define MSM_CAM_IOCTL_CONFIG_VFE  \
	_IOW(MSM_CAM_IOCTL_MAGIC, 5, struct msm_camera_vfe_cfg_cmd *)

#define MSM_CAM_IOCTL_GET_STATS \
	_IOR(MSM_CAM_IOCTL_MAGIC, 6, struct msm_camera_stats_event_ctrl *)

#define MSM_CAM_IOCTL_GETFRAME \
	_IOR(MSM_CAM_IOCTL_MAGIC, 7, struct msm_camera_get_frame *)

#define MSM_CAM_IOCTL_ENABLE_VFE \
	_IOW(MSM_CAM_IOCTL_MAGIC, 8, struct camera_enable_cmd *)

#define MSM_CAM_IOCTL_CTRL_CMD_DONE \
	_IOW(MSM_CAM_IOCTL_MAGIC, 9, struct camera_cmd *)

#define MSM_CAM_IOCTL_CONFIG_CMD \
	_IOW(MSM_CAM_IOCTL_MAGIC, 10, struct camera_cmd *)

#define MSM_CAM_IOCTL_DISABLE_VFE \
	_IOW(MSM_CAM_IOCTL_MAGIC, 11, struct camera_enable_cmd *)

#define MSM_CAM_IOCTL_PAD_REG_RESET2 \
	_IOW(MSM_CAM_IOCTL_MAGIC, 12, struct camera_enable_cmd *)

#define MSM_CAM_IOCTL_VFE_APPS_RESET \
	_IOW(MSM_CAM_IOCTL_MAGIC, 13, struct camera_enable_cmd *)

#define MSM_CAM_IOCTL_RELEASE_FRAME_BUFFER \
	_IOW(MSM_CAM_IOCTL_MAGIC, 14, struct camera_enable_cmd *)

#define MSM_CAM_IOCTL_RELEASE_STATS_BUFFER \
	_IOW(MSM_CAM_IOCTL_MAGIC, 15, struct msm_stats_buf *)

#define MSM_CAM_IOCTL_AXI_CONFIG \
	_IOW(MSM_CAM_IOCTL_MAGIC, 16, struct msm_camera_vfe_cfg_cmd *)

#define MSM_CAM_IOCTL_GET_PICTURE \
	_IOW(MSM_CAM_IOCTL_MAGIC, 17, struct msm_camera_ctrl_cmd *)

#define MSM_CAM_IOCTL_SET_CROP \
	_IOW(MSM_CAM_IOCTL_MAGIC, 18, struct crop_info *)

#define MSM_CAM_IOCTL_PICT_PP \
	_IOW(MSM_CAM_IOCTL_MAGIC, 19, uint8_t *)

#define MSM_CAM_IOCTL_PICT_PP_DONE \
	_IOW(MSM_CAM_IOCTL_MAGIC, 20, struct msm_snapshot_pp_status *)

#define MSM_CAM_IOCTL_SENSOR_IO_CFG \
	_IOW(MSM_CAM_IOCTL_MAGIC, 21, struct sensor_cfg_data *)

#define MSM_CAMERA_LED_OFF  0
#define MSM_CAMERA_LED_LOW  1
#define MSM_CAMERA_LED_HIGH 2

#define MSM_CAM_IOCTL_FLASH_LED_CFG \
	_IOW(MSM_CAM_IOCTL_MAGIC, 22, unsigned *)

#define MSM_CAM_IOCTL_UNBLOCK_POLL_FRAME \
	_IO(MSM_CAM_IOCTL_MAGIC, 23)

#define MSM_CAM_IOCTL_CTRL_COMMAND_2 \
	_IOW(MSM_CAM_IOCTL_MAGIC, 24, struct msm_ctrl_cmd *)

#define MSM_CAM_IOCTL_AF_CTRL \
	_IOR(MSM_CAM_IOCTL_MAGIC, 25, struct msm_ctrl_cmt_t *)
#define MSM_CAM_IOCTL_AF_CTRL_DONE \
	_IOW(MSM_CAM_IOCTL_MAGIC, 26, struct msm_ctrl_cmt_t *)

/* FIH, Charles Huang, 2009/11/09 { */
/* [FXX_CR], new function  */
#ifdef CONFIG_FIH_FXX
#define MSM_CAM_IOCTL_GET_FIH_SENSOR_INFO \
	_IOR(MSM_CAM_IOCTL_MAGIC, 27, struct msm_camsensor_info *)
#endif
/* } FIH, Charles Huang, 2009/11/09 */

#define MAX_SENSOR_NUM  3
#define MAX_SENSOR_NAME 32

#define PP_SNAP  0x01
#define PP_RAW_SNAP ((0x01)<<1)
#define PP_PREV  ((0x01)<<2)
#define PP_MASK		(PP_SNAP|PP_RAW_SNAP|PP_PREV)

#define MSM_CAM_CTRL_CMD_DONE  0
#define MSM_CAM_SENSOR_VFE_CMD 1

/*****************************************************
 *  structure
 *****************************************************/

/* define five type of structures for userspace <==> kernel
 * space communication:
 * command 1 - 2 are from userspace ==> kernel
 * command 3 - 4 are from kernel ==> userspace
 *
 * 1. control command: control command(from control thread),
 *                     control status (from config thread);
 */
struct msm_ctrl_cmd {
	uint16_t type;
	uint16_t length;
	void *value;
	uint16_t status;
	uint32_t timeout_ms;
	int resp_fd; /* FIXME: to be used by the kernel, pass-through for now */
};

struct msm_vfe_evt_msg {
	unsigned short type;	/* 1 == event (RPC), 0 == message (adsp) */
	unsigned short msg_id;
	unsigned int len;	/* size in, number of bytes out */
	void *data;
};

#define MSM_CAM_RESP_CTRL         0
#define MSM_CAM_RESP_STAT_EVT_MSG 1
#define MSM_CAM_RESP_V4L2         2
#define MSM_CAM_RESP_MAX          3

/* this one is used to send ctrl/status up to config thread */
struct msm_stats_event_ctrl {
	/* 0 - ctrl_cmd from control thread,
	 * 1 - stats/event kernel,
	 * 2 - V4L control or read request */
	int resptype;
	int timeout_ms;
	struct msm_ctrl_cmd ctrl_cmd;
	/* struct  vfe_event_t  stats_event; */
	struct msm_vfe_evt_msg stats_event;
};

/* 2. config command: config command(from config thread); */
struct msm_camera_cfg_cmd {
	/* what to config:
	 * 1 - sensor config, 2 - vfe config */
	uint16_t cfg_type;

	/* sensor config type */
	uint16_t cmd_type;
	uint16_t queue;
	uint16_t length;
	void *value;
};

#define CMD_GENERAL			0
#define CMD_AXI_CFG_OUT1		1
#define CMD_AXI_CFG_SNAP_O1_AND_O2	2
#define CMD_AXI_CFG_OUT2		3
#define CMD_PICT_T_AXI_CFG		4
#define CMD_PICT_M_AXI_CFG		5
#define CMD_RAW_PICT_AXI_CFG		6

#define CMD_FRAME_BUF_RELEASE		7
#define CMD_PREV_BUF_CFG		8
#define CMD_SNAP_BUF_RELEASE		9
#define CMD_SNAP_BUF_CFG		10
#define CMD_STATS_DISABLE		11
#define CMD_STATS_AEC_AWB_ENABLE	12
#define CMD_STATS_AF_ENABLE		13
#define CMD_STATS_AEC_ENABLE		14
#define CMD_STATS_AWB_ENABLE		15
#define CMD_STATS_ENABLE  		16

#define CMD_STATS_AXI_CFG		17
#define CMD_STATS_AEC_AXI_CFG		18
#define CMD_STATS_AF_AXI_CFG 		19
#define CMD_STATS_AWB_AXI_CFG		20
#define CMD_STATS_RS_AXI_CFG		21
#define CMD_STATS_CS_AXI_CFG		22
#define CMD_STATS_IHIST_AXI_CFG		23
#define CMD_STATS_SKIN_AXI_CFG		24

#define CMD_STATS_BUF_RELEASE		25
#define CMD_STATS_AEC_BUF_RELEASE	26
#define CMD_STATS_AF_BUF_RELEASE	27
#define CMD_STATS_AWB_BUF_RELEASE	28
#define CMD_STATS_RS_BUF_RELEASE	29
#define CMD_STATS_CS_BUF_RELEASE	30
#define CMD_STATS_IHIST_BUF_RELEASE	31
#define CMD_STATS_SKIN_BUF_RELEASE	32

#define UPDATE_STATS_INVALID		33
#define CMD_AXI_CFG_SNAP_GEMINI		34
#define CMD_AXI_CFG_SNAP		35
#define CMD_AXI_CFG_PREVIEW		36
#define CMD_AXI_CFG_VIDEO		37

/* vfe config command: config command(from config thread)*/
struct msm_vfe_cfg_cmd {
	int cmd_type;
	uint16_t length;
	void *value;
};

#define MAX_CAMERA_ENABLE_NAME_LEN 32
struct camera_enable_cmd {
	char name[MAX_CAMERA_ENABLE_NAME_LEN];
};

#define MSM_PMEM_OUTPUT1		0
#define MSM_PMEM_OUTPUT2		1
#define MSM_PMEM_OUTPUT1_OUTPUT2	2
#define MSM_PMEM_THUMBNAIL		3
#define MSM_PMEM_MAINIMG		4
#define MSM_PMEM_RAW_MAINIMG		5
#define MSM_PMEM_AEC_AWB		6
#define MSM_PMEM_AF			7
#define MSM_PMEM_AEC			8
#define MSM_PMEM_AWB			9
#define MSM_PMEM_RS		    	10
#define MSM_PMEM_CS	    		11
#define MSM_PMEM_IHIST			12
#define MSM_PMEM_SKIN			13
#define MSM_PMEM_VIDEO			14
#define MSM_PMEM_PREVIEW		15
#define MSM_PMEM_MAX			16


#define STAT_AEAW			0
#define STAT_AEC			1
#define STAT_AF				2
#define STAT_AWB			3
#define STAT_RS				4
#define STAT_CS				5
#define STAT_IHIST			6
#define STAT_SKIN			7
#define STAT_MAX			8

#define FRAME_PREVIEW_OUTPUT1		0
#define FRAME_PREVIEW_OUTPUT2		1
#define FRAME_SNAPSHOT			2
#define FRAME_THUMBNAIL			3
#define FRAME_RAW_SNAPSHOT		4
#define FRAME_MAX			5

struct msm_pmem_info {
	int type;
	int fd;
	void *vaddr;
	uint32_t offset;
	uint32_t len;
	uint32_t y_off;
	uint32_t cbcr_off;
	uint8_t active;
};

struct outputCfg {
	uint32_t height;
	uint32_t width;

	uint32_t window_height_firstline;
	uint32_t window_height_lastline;
};

#define OUTPUT_1	0
#define OUTPUT_2	1
#define OUTPUT_1_AND_2            2   /* snapshot only */
#define OUTPUT_1_AND_3            3   /* video */
#define CAMIF_TO_AXI_VIA_OUTPUT_2 4
#define OUTPUT_1_AND_CAMIF_TO_AXI_VIA_OUTPUT_2 5
#define OUTPUT_2_AND_CAMIF_TO_AXI_VIA_OUTPUT_1 6
#define LAST_AXI_OUTPUT_MODE_ENUM = OUTPUT_2_AND_CAMIF_TO_AXI_VIA_OUTPUT_1 7

#define MSM_FRAME_PREV_1	0
#define MSM_FRAME_PREV_2	1
#define MSM_FRAME_ENC		2

#define OUTPUT_TYPE_P		1
#define OUTPUT_TYPE_T		2
#define OUTPUT_TYPE_S		3
#define OUTPUT_TYPE_V		4

struct msm_frame {
	int path;
	unsigned long buffer;
	uint32_t y_off;
	uint32_t cbcr_off;
	int fd;

	void *cropinfo;
	int croplen;
};

struct msm_stats_buf {
	int type;
	unsigned long buffer;
	int fd;
};

#define MSM_V4L2_VID_CAP_TYPE	0
#define MSM_V4L2_STREAM_ON	1
#define MSM_V4L2_STREAM_OFF	2
#define MSM_V4L2_SNAPSHOT	3
#define MSM_V4L2_QUERY_CTRL	4
#define MSM_V4L2_GET_CTRL	5
#define MSM_V4L2_SET_CTRL	6
#define MSM_V4L2_QUERY		7
#define MSM_V4L2_GET_CROP	8
#define MSM_V4L2_SET_CROP	9
#define MSM_V4L2_MAX		10

#define V4L2_CAMERA_EXIT 	43
struct crop_info {
	void *info;
	int len;
};

struct msm_postproc {
	int ftnum;
	struct msm_frame fthumnail;
	int fmnum;
	struct msm_frame fmain;
};

struct msm_snapshot_pp_status {
	void *status;
};

#define CFG_SET_MODE			0
#define CFG_SET_EFFECT			1
#define CFG_START			2
#define CFG_PWR_UP			3
#define CFG_PWR_DOWN			4
#define CFG_WRITE_EXPOSURE_GAIN		5
#define CFG_SET_DEFAULT_FOCUS		6
#define CFG_MOVE_FOCUS			7
#define CFG_REGISTER_TO_REAL_GAIN	8
#define CFG_REAL_TO_REGISTER_GAIN	9
#define CFG_SET_FPS			10
#define CFG_SET_PICT_FPS		11
#define CFG_SET_BRIGHTNESS		12
#define CFG_SET_CONTRAST		13
#define CFG_SET_ZOOM			14
#define CFG_SET_EXPOSURE_MODE		15
#define CFG_SET_WB			16
#define CFG_SET_ANTIBANDING		17
#define CFG_SET_EXP_GAIN		18
#define CFG_SET_PICT_EXP_GAIN		19
#define CFG_SET_LENS_SHADING		20
#define CFG_GET_PICT_FPS		21
#define CFG_GET_PREV_L_PF		22
#define CFG_GET_PREV_P_PL		23
#define CFG_GET_PICT_L_PF		24
#define CFG_GET_PICT_P_PL		25
#define CFG_GET_AF_MAX_STEPS		26
#define CFG_GET_PICT_MAX_EXP_LC		27
/* FIH, Charles Huang, 2009/10/28 { */
/* [FXX_CR], new function  */
#ifdef CONFIG_FIH_FXX
#define CFG_SET_LEDMOD		28
#define CFG_SET_EXPOSUREMOD		29
#define CFG_SET_SATURATION		30
#define CFG_SET_SHARPNESS		31
#define CFG_SET_HUE		32
#define CFG_SET_GAMMA		33
#define CFG_SET_AUTOEXPOSURE		34
#define CFG_SET_AUTOFOCUS		35
#define CFG_SET_METERINGMOD		36
#define CFG_SET_SCENEMOD		37
#define CFG_MAX				38
#else
#define CFG_MAX				28
#endif
/* } FIH, Charles Huang, 2009/10/28 */


#define MOVE_NEAR	0
#define MOVE_FAR	1

#define SENSOR_PREVIEW_MODE		0
#define SENSOR_SNAPSHOT_MODE		1
#define SENSOR_RAW_SNAPSHOT_MODE	2

#define SENSOR_QTR_SIZE			0
#define SENSOR_FULL_SIZE		1
#define SENSOR_INVALID_SIZE		2

#define CAMERA_EFFECT_OFF		0
#define CAMERA_EFFECT_MONO		1
#define CAMERA_EFFECT_NEGATIVE		2
#define CAMERA_EFFECT_SOLARIZE		3
#define CAMERA_EFFECT_SEPIA		4
#define CAMERA_EFFECT_POSTERIZE		5
#define CAMERA_EFFECT_WHITEBOARD	6
#define CAMERA_EFFECT_BLACKBOARD	7
#define CAMERA_EFFECT_AQUA		8
/* FIH, Charles Huang, 2009/07/30 { */
/* [FXX_CR], add new effect to meet requirement */
#ifdef CONFIG_FIH_FXX
#define CAMERA_EFFECT_BLUISH		9
#define CAMERA_EFFECT_REDDISH		10
#define CAMERA_EFFECT_GREENISH		11
#define CAMERA_EFFECT_MAX		12
#else
#define CAMERA_EFFECT_MAX		9
#endif
/* } FIH, Charles Huang, 2009/07/30 */

/* FIH, Charles Huang, 2009/10/28 { */
/* [FXX_CR], add new param to meet requirement */
#ifdef CONFIG_FIH_FXX
/* White balancing type, used for CAMERA_PARM_WHITE_BALANCING */
#define CAMERA_WB_MIN_MINUS_1		0
#define CAMERA_WB_AUTO			1
#define CAMERA_WB_CUSTOM		2
#define CAMERA_WB_INCANDESCENT		3
#define CAMERA_WB_FLUORESCENT		4
#define CAMERA_WB_DAYLIGHT		5
#define CAMERA_WB_CLOUDY_DAYLIGHT	6
#define CAMERA_WB_TWILIGHT		7
#define CAMERA_WB_SHADE			8
#define CAMERA_WB_1			9
#define CAMERA_WB_2			10
#define CAMERA_WB_3			11
#define CAMERA_WB_MAX_PLUS_1		12
#endif
/* } FIH, Charles Huang, 2009/10/28 */

/* FIH, Charles Huang, 2009/07/15 { */
/* [FXX_CR], add new param to meet requirement */
#ifdef CONFIG_FIH_FXX
/* White balancing type, used for CAMERA_PARM_WHITE_BALANCING */
#define CAMERA_BRIGHTNESS_MIN		0
#define CAMERA_BRIGHTNESS_0		0
#define CAMERA_BRIGHTNESS_1		1
#define CAMERA_BRIGHTNESS_2		2
#define CAMERA_BRIGHTNESS_3		3
#define CAMERA_BRIGHTNESS_4		4
#define CAMERA_BRIGHTNESS_5		5
#define CAMERA_BRIGHTNESS_DEFAULT	5
#define CAMERA_BRIGHTNESS_6		6
#define CAMERA_BRIGHTNESS_7		7
#define CAMERA_BRIGHTNESS_8		8
#define CAMERA_BRIGHTNESS_9		9
#define CAMERA_BRIGHTNESS_10		10
#define CAMERA_BRIGHTNESS_MAX		10
#endif
/* } FIH, Charles Huang, 2009/07/15 */

/* FIH, Charles Huang, 2009/07/15 { */
/* [FXX_CR], add new param to meet requirement */
#ifdef CONFIG_FIH_FXX
/* White balancing type, used for CAMERA_PARM_WHITE_BALANCING */
#define CAMERA_ANTIBANDING_OFF		0
#define CAMERA_ANTIBANDING_60HZ	1
#define CAMERA_ANTIBANDING_50HZ	2
#define CAMERA_ANTIBANDING_AUTO	3
#define CAMERA_MAX_ANTIBANDING		4
#endif
/* } FIH, Charles Huang, 2009/07/15 */

/* FIH, Charles Huang, 2009/09/01 { */
/* [FXX_CR], flashlight function  */
#ifdef CONFIG_FIH_FXX
#define CAMERA_LED_MODE_OFF 0
#define CAMERA_LED_MODE_AUTO 1
#define CAMERA_LED_MODE_ON 2
#endif
/* } FIH, Charles Huang, 2009/09/01 */

/* FIH, Charles Huang, 2009/11/04 { */
/* [FXX_CR], af function  */
#ifdef CONFIG_FIH_FXX
#define CAMERA_AUTOFOCUS 0
#endif
/* } FIH, Charles Huang, 2009/11/04 */

/* FIH, Charles Huang, 2009/11/05 { */
/* [FXX_CR], metering mode function  */
#ifdef CONFIG_FIH_FXX
#define CAMERA_AVERAGE_METERING 0
#define CAMERA_CENTER_METERING 1
#define CAMERA_SPOT_METERING 2
#endif
/* } FIH, Charles Huang, 2009/11/05 */

/* FIH, Charles Huang, 2009/11/05 { */
/* [FXX_CR], scene mode function  */
#ifdef CONFIG_FIH_FXX
#define CAMERA_SCENE_MODE_AUTO 0
#define CAMERA_SCENE_MODE_LANDSCAPE 1
#define CAMERA_SCENE_MODE_PORTRAIT 2
#define CAMERA_SCENE_MODE_NIGHT 3
#define CAMERA_SCENE_MODE_NIGHT_PORTRAIT 4
#define CAMERA_SCENE_MODE_SUNSET 5
#endif
/* } FIH, Charles Huang, 2009/11/05 */

/* FIH, Charles Huang, 2009/11/05 { */
/* [FXX_CR], contrast function  */
#ifdef CONFIG_FIH_FXX
#define CAMERA_CONTRAST_MINUS_2 0
#define CAMERA_CONTRAST_MINUS_1 1
#define CAMERA_CONTRAST_ZERO 2
#define CAMERA_CONTRAST_POSITIVE_1 3
#define CAMERA_CONTRAST_POSITIVE_2 4
#endif
/* } FIH, Charles Huang, 2009/11/05 */

/* FIH, Charles Huang, 2009/11/05 { */
/* [FXX_CR], saturation function  */
#ifdef CONFIG_FIH_FXX
#define CAMERA_SATURATION_MINUS_2 0
#define CAMERA_SATURATION_MINUS_1 1
#define CAMERA_SATURATION_ZERO 2
#define CAMERA_SATURATION_POSITIVE_1 3
#define CAMERA_SATURATION_POSITIVE_2 4
#endif
/* } FIH, Charles Huang, 2009/11/05 */

/* FIH, Charles Huang, 2009/11/05 { */
/* [FXX_CR], sharpness function  */
#ifdef CONFIG_FIH_FXX
#define CAMERA_SHARPNESS_ZERO 0
#define CAMERA_SHARPNESS_POSITIVE_1 1
#define CAMERA_SHARPNESS_POSITIVE_2 2
#endif
/* } FIH, Charles Huang, 2009/11/05 */

struct sensor_pict_fps {
	uint16_t prevfps;
	uint16_t pictfps;
};

struct exp_gain_cfg {
	uint16_t gain;
	uint32_t line;
};

struct focus_cfg {
	int32_t steps;
	int dir;
};

struct fps_cfg {
	uint16_t f_mult;
	uint16_t fps_div;
	uint32_t pict_fps_div;
};

struct sensor_cfg_data {
	int cfgtype;
	int mode;
	int rs;
	uint8_t max_steps;

	union {
		int8_t effect;
/* FIH, Charles Huang, 2009/07/15 { */
/* [FXX_CR], add new param to meet requirement */
#ifdef CONFIG_FIH_FXX
		int8_t wb;
		int8_t antibanding;
		int8_t brightness;
#endif
/* } FIH, Charles Huang, 2009/07/15 */
/* FIH, Charles Huang, 2009/09/01 { */
/* [FXX_CR], flashlight function  */
#ifdef CONFIG_FIH_FXX
		int8_t ledmod;
#endif
/* } FIH, Charles Huang, 2009/09/01 */
/* FIH, Charles Huang, 2009/10/28 { */
/* [FXX_CR], exposuremod function  */
#ifdef CONFIG_FIH_FXX
		int8_t exposuremod;
#endif
/* } FIH, Charles Huang, 2009/10/28 */
/* FIH, Charles Huang, 2009/10/28 { */
/* [FXX_CR], saturation function  */
#ifdef CONFIG_FIH_FXX
		int8_t saturation;
#endif
/* } FIH, Charles Huang, 2009/10/28 */
/* FIH, Charles Huang, 2009/10/28 { */
/* [FXX_CR], sharpness function  */
#ifdef CONFIG_FIH_FXX
		int8_t sharpness;
#endif
/* } FIH, Charles Huang, 2009/10/28 */
/* FIH, Charles Huang, 2009/10/28 { */
/* [FXX_CR], contrast function  */
#ifdef CONFIG_FIH_FXX
		int8_t contrast;
#endif
/* } FIH, Charles Huang, 2009/10/28 */
/* FIH, Charles Huang, 2009/10/28 { */
/* [FXX_CR], hue function  */
#ifdef CONFIG_FIH_FXX
		int8_t hue;
#endif
/* } FIH, Charles Huang, 2009/10/28 */
/* FIH, Charles Huang, 2009/10/28 { */
/* [FXX_CR], gamma function  */
#ifdef CONFIG_FIH_FXX
		int8_t gamma;
#endif
/* } FIH, Charles Huang, 2009/10/28 */
/* FIH, Charles Huang, 2009/10/28 { */
/* [FXX_CR], autoexposure function  */
#ifdef CONFIG_FIH_FXX
		int8_t autoexposure;
#endif
/* } FIH, Charles Huang, 2009/10/28 */
/* FIH, Charles Huang, 2009/11/04 { */
/* [FXX_CR], af function  */
#ifdef CONFIG_FIH_FXX
		int8_t autofocus;
#endif
/* } FIH, Charles Huang, 2009/11/04 */
/* FIH, Charles Huang, 2009/11/05 { */
/* [FXX_CR], metering mode function  */
#ifdef CONFIG_FIH_FXX
		int8_t meteringmod;
#endif
/* } FIH, Charles Huang, 2009/11/05 */
/* FIH, Charles Huang, 2009/11/05 { */
/* [FXX_CR], scene mode function  */
#ifdef CONFIG_FIH_FXX
		int8_t scenemod;
#endif
/* } FIH, Charles Huang, 2009/11/05 */
		uint8_t lens_shading;
		uint16_t prevl_pf;
		uint16_t prevp_pl;
		uint16_t pictl_pf;
		uint16_t pictp_pl;
		uint32_t pict_max_exp_lc;
		uint16_t p_fps;
		struct sensor_pict_fps gfps;
		struct exp_gain_cfg exp_gain;
		struct focus_cfg focus;
		struct fps_cfg fps;
	} cfg;
};

#define GET_NAME			0
#define GET_PREVIEW_LINE_PER_FRAME	1
#define GET_PREVIEW_PIXELS_PER_LINE	2
#define GET_SNAPSHOT_LINE_PER_FRAME	3
#define GET_SNAPSHOT_PIXELS_PER_LINE	4
#define GET_SNAPSHOT_FPS		5
#define GET_SNAPSHOT_MAX_EP_LINE_CNT	6

struct msm_camsensor_info {
	char name[MAX_SENSOR_NAME];
	uint8_t flash_enabled;
	int8_t total_steps;
};
#endif /* __LINUX_MSM_CAMERA_H */

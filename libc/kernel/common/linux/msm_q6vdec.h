/****************************************************************************
 ****************************************************************************
 ***
 ***   This header was automatically generated from a Linux kernel header
 ***   of the same name, to make information necessary for userspace to
 ***   call into the kernel available to libc.  It contains only constants,
 ***   structures, and macros generated from the original header, and thus,
 ***   contains no copyrightable information.
 ***
 ****************************************************************************
 ****************************************************************************/
#ifndef _MSM_VDEC_H_
#define _MSM_VDEC_H_

#include <linux/types.h>

#define VDEC_IOCTL_MAGIC 'v'

#define VDEC_IOCTL_INITIALIZE _IOWR(VDEC_IOCTL_MAGIC, 1, struct vdec_init)
#define VDEC_IOCTL_SETBUFFERS _IOW(VDEC_IOCTL_MAGIC, 2, struct vdec_buffer)
#define VDEC_IOCTL_QUEUE _IOWR(VDEC_IOCTL_MAGIC, 3,   struct vdec_input_buf)
#define VDEC_IOCTL_REUSEFRAMEBUFFER _IOW(VDEC_IOCTL_MAGIC, 4, unsigned int)
#define VDEC_IOCTL_FLUSH _IOW(VDEC_IOCTL_MAGIC, 5, unsigned int)
#define VDEC_IOCTL_EOS _IO(VDEC_IOCTL_MAGIC, 6)
#define VDEC_IOCTL_GETMSG _IOR(VDEC_IOCTL_MAGIC, 7, struct vdec_msg)
#define VDEC_IOCTL_CLOSE _IO(VDEC_IOCTL_MAGIC, 8)
#define VDEC_IOCTL_FREEBUFFERS _IOW(VDEC_IOCTL_MAGIC, 9, struct vdec_buf_info)
#define VDEC_IOCTL_GETDECATTRIBUTES _IOR(VDEC_IOCTL_MAGIC, 10,   struct vdec_dec_attributes)
#define VDEC_IOCTL_GETVERSION _IOR(VDEC_IOCTL_MAGIC, 11, struct vdec_version)
#define VDEC_IOCTL_SETPROPERTY _IOW(VDEC_IOCTL_MAGIC, 12, struct vdec_property_info)
#define VDEC_IOCTL_GETPROPERTY _IOR(VDEC_IOCTL_MAGIC, 13, struct vdec_property_info)

enum {
 VDEC_FRAME_DECODE_OK,
 VDEC_FRAME_DECODE_ERR,
 VDEC_FATAL_ERR,
 VDEC_FLUSH_FINISH,
 VDEC_EOS,
 VDEC_FRAME_FLUSH,
 VDEC_STREAM_SWITCH,
 VDEC_SUSPEND_FINISH,
 VDEC_BUFFER_CONSUMED
};

enum {
 VDEC_FLUSH_INPUT,
 VDEC_FLUSH_OUTPUT,
 VDEC_FLUSH_ALL
};

enum {
 VDEC_BUFFER_TYPE_INPUT,
 VDEC_BUFFER_TYPE_OUTPUT,
 VDEC_BUFFER_TYPE_INTERNAL1,
 VDEC_BUFFER_TYPE_INTERNAL2,
};

enum {
 VDEC_QUEUE_SUCCESS,
 VDEC_QUEUE_FAILED,
 VDEC_QUEUE_BADSTATE,
};

enum {
 VDEC_COLOR_FORMAT_NV21 = 0x01,
 VDEC_COLOR_FORMAT_NV21_YAMOTO = 0x02
 };

enum vdec_property_id {
   VDEC_FOURCC,
   VDEC_PROFILE,
   VDEC_LEVEL,
   VDEC_DIMENSIONS,
   VDEC_CWIN,
   VDEC_INPUT_BUF_REQ,
   VDEC_OUTPUT_BUF_REQ,
   VDEC_LUMA_CHROMA_STRIDE,
   VDEC_NUM_DAL_PORTS,
   VDEC_PRIORITY,
   VDEC_FRAME_ALIGNMENT
};

struct vdec_input_buf_info {
 u32 offset;
 u32 data;
 u32 size;
 int timestamp_lo;
 int timestamp_hi;
 int avsync_state;
 u32 flags;
};

struct vdec_buf_desc {
 u32 bufsize;
 u32 num_min_buffers;
 u32 num_max_buffers;
};

struct vdec_buf_req {
 u32 max_input_queue_size;
 struct vdec_buf_desc input;
 struct vdec_buf_desc output;
 struct vdec_buf_desc dec_req1;
 struct vdec_buf_desc dec_req2;
};

struct vdec_region_info {
 u32 src_id;
 u32 offset;
 u32 size;
};

struct vdec_config {
 u32 fourcc;
 u32 width;
 u32 height;
 u32 order;
 u32 notify_enable;
 u32 vc1_rowbase;
 u32 h264_startcode_detect;
 u32 h264_nal_len_size;
 u32 postproc_flag;
 u32 fruc_enable;
 u32 color_format;
};

struct vdec_vc1_panscan_regions {
 int num;
 int width[4];
 int height[4];
 int xoffset[4];
 int yoffset[4];
};

struct vdec_cropping_window {
 u32 x1;
 u32 y1;
 u32 x2;
 u32 y2;
};

struct vdec_frame_info {
 u32 status;
 u32 offset;
 u32 data1;
 u32 data2;
 int timestamp_lo;
 int timestamp_hi;
 int cal_timestamp_lo;
 int cal_timestamp_hi;
 u32 dec_width;
 u32 dec_height;
 struct vdec_cropping_window cwin;
 u32 picture_type[2];
 u32 picture_format;
 u32 vc1_rangeY;
 u32 vc1_rangeUV;
 u32 picture_resolution;
 u32 frame_disp_repeat;
 u32 repeat_first_field;
 u32 top_field_first;
 u32 interframe_interp;
 struct vdec_vc1_panscan_regions panscan;
 u32 concealed_macblk_num;
 u32 flags;
 u32 performance_stats;
 u32 data3;
};

struct vdec_buf_info {
 u32 buf_type;
 struct vdec_region_info region;
 u32 num_buf;
 u32 islast;
};

struct vdec_buffer {
 u32 pmem_id;
 struct vdec_buf_info buf;
};

struct vdec_sequence {
 u8 *header;
 u32 len;
};

struct vdec_config_sps {
 struct vdec_config cfg;
 struct vdec_sequence seq;
};

#define VDEC_MSG_REUSEINPUTBUFFER 1
#define VDEC_MSG_FRAMEDONE 2

struct vdec_msg {
 u32 id;

 union {

 u32 buf_id;

 struct vdec_frame_info vfr_info;
 };
};

struct vdec_init {
 struct vdec_config_sps sps_cfg;
 struct vdec_buf_req *buf_req;
};

struct vdec_input_buf {
 u32 pmem_id;
 struct vdec_input_buf_info buffer;
 struct vdec_queue_status *queue_status;
};

struct vdec_queue_status {
 u32 status;
};

struct vdec_dec_attributes {
 u32 fourcc;
 u32 profile;
 u32 level;
 u32 dec_pic_width;
 u32 dec_pic_height;
 struct vdec_buf_desc input;
 struct vdec_buf_desc output;
 struct vdec_buf_desc dec_req1;
 struct vdec_buf_desc dec_req2;
};

struct vdec_version {
 u32 major;
 u32 minor;
};

struct dal_vdec_rectangle {
   u32 width;
   u32 height;
};

struct stride_type {
   u32 luma;
   u32 chroma;
};

struct frame_alignment_type {
   u32 luma_width;
   u32 luma_height;
   u32 chroma_width;
   u32 chroma_height;
   u32 chroma_offset;
};

union vdec_property {
   u32 fourcc;
   u32 profile;
   u32 level;
   struct dal_vdec_rectangle dim;
   struct vdec_cropping_window cw;
   struct vdec_buf_desc input_req;
   struct vdec_buf_desc output_req;
   struct stride_type stride;
   u32 num_dal_ports;
   u32 priority;
   struct frame_alignment_type frame_alignment;
   u32 def_type;
};

struct vdec_property_info {
   enum vdec_property_id id;
   union vdec_property property;
};
#endif /* _MSM_VDEC_H_ */

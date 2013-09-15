/* Copyright (c) 2010, Code Aurora Forum. All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are
 * met:
 *     * Redistributions of source code must retain the above copyright
 *       notice, this list of conditions and the following disclaimer.
 *     * Redistributions in binary form must reproduce the above
 *       copyright notice, this list of conditions and the following
 *       disclaimer in the documentation and/or other materials provided
 *       with the distribution.
 *     * Neither the name of Code Aurora Forum, Inc. nor the names of its
 *       contributors may be used to endorse or promote products derived
 *       from this software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED "AS IS" AND ANY EXPRESS OR IMPLIED
 * WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF
 * MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NON-INFRINGEMENT
 * ARE DISCLAIMED.  IN NO EVENT SHALL THE COPYRIGHT OWNER OR CONTRIBUTORS
 * BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
 * CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
 * SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR
 * BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY,
 * WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE
 * OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN
 * IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 *
 */
#ifndef __MACH_QDSP6V2_SNDDEV_ICODEC_H
#define __MACH_QDSP6V2_SNDDEV_ICODEC_H
#include <linux/mfd/msm-adie-codec.h>
#include <mach/qdsp5v2/audio_def.h>
#include <linux/spi_aic3254.h>
#include <mach/pmic.h>

struct snddev_icodec_data {
	u32 capability; /* RX or TX */
	const char *name;
	u32 copp_id; /* audpp routing */
	/* Adie profile */
	struct adie_codec_dev_profile *profile;
	/* Afe setting */
	u8 channel_mode;
	u32 default_sample_rate;
	void (*pamp_on) (int on);
	void (*voltage_on) (int on);
	u32 dev_vol_type;
	u32 aic3254_id;
	u32 aic3254_voc_id;
	u32 default_aic3254_id;
};

/* Context for each internal codec sound device */
struct snddev_icodec_state {
	struct snddev_icodec_data *data;
	struct adie_codec_path *adie_path;
	u32 sample_rate;
	u32 enabled;
};

struct q6v2audio_analog_ops {
	void (*speaker_enable)(int en);
	void (*headset_enable)(int en);
	void (*handset_enable)(int en);
	void (*bt_sco_enable)(int en);
	void (*headset_speaker_enable)(int en);
	void (*int_mic_enable)(int en);
	void (*back_mic_enable)(int en);
	void (*ext_mic_enable)(int en);
	void (*stereo_mic_enable)(int en);
	void (*usb_headset_enable)(int en);
	void (*fm_headset_enable)(int en);
	void (*fm_speaker_enable)(int en);
	void (*voltage_on) (int on);
};

struct q6v2audio_icodec_ops {
	int (*support_aic3254) (void);
	int (*support_adie) (void);
	int (*is_msm_i2s_slave) (void);
	int (*support_aic3254_use_mclk) (void);
};

struct q6v2audio_aic3254_ops {
	void (*aic3254_set_mode)(int config, int mode);
};

struct aic3254_info {
	u32 dev_id;
	u32 path_id;
};


void htc_8x60_register_analog_ops(struct q6v2audio_analog_ops *ops);
void htc_8x60_register_aic3254_ops(struct q6v2audio_aic3254_ops *ops);
int update_aic3254_info(struct aic3254_info *info);
void htc_8x60_register_icodec_ops(struct q6v2audio_icodec_ops *ops);
#endif

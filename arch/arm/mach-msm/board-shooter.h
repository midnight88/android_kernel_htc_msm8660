/* linux/arch/arm/mach-msm/board-spade.h
 *
 * Copyright (C) 2010-2011 HTC Corporation.
 *
 * This software is licensed under the terms of the GNU General Public
 * License version 2, as published by the Free Software Foundation, and
 * may be copied, distributed, and modified under those terms.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 */

#ifndef __ARCH_ARM_MACH_MSM_BOARD_shooter_H
#define __ARCH_ARM_MACH_MSM_BOARD_shooter_H

#include <mach/board.h>

#define SHOOTER_PROJECT_NAME	"shooter"

#define MSM_RAM_CONSOLE_BASE	MSM_HTC_RAM_CONSOLE_PHYS
#define MSM_RAM_CONSOLE_SIZE	MSM_HTC_RAM_CONSOLE_SIZE


#if defined(CONFIG_CRYPTO_DEV_QCRYPTO) || \
		defined(CONFIG_CRYPTO_DEV_QCRYPTO_MODULE) || \
		defined(CONFIG_CRYPTO_DEV_QCEDEV) || \
		defined(CONFIG_CRYPTO_DEV_QCEDEV_MODULE)
#define QCE_SIZE		0x10000
#define QCE_0_BASE		0x18500000
#endif

#ifdef CONFIG_FB_MSM_LCDC_DSUB
#define MSM_FB_DSUB_PMEM_ADDER (0x9E3400-0x4B0000)
#else
#define MSM_FB_DSUB_PMEM_ADDER (0)
#endif

#ifdef CONFIG_FB_MSM_TRIPLE_BUFFER
#define MSM_FB_PRIM_BUF_SIZE (960 * ALIGN(540, 32) * 4 * 3)
#else
#define MSM_FB_PRIM_BUF_SIZE (960 * ALIGN(540, 32) * 4 * 2)
#endif


#ifdef CONFIG_FB_MSM_OVERLAY0_WRITEBACK
#define MSM_FB_WRITEBACK_SIZE roundup(960 * ALIGN(540, 32) * 3 * 2, 4096)
#else
#define MSM_FB_WRITEBACK_SIZE 0
#endif

#ifdef CONFIG_FB_MSM_HDMI_MSM_PANEL
#define MSM_FB_SIZE roundup(MSM_FB_PRIM_BUF_SIZE + 0x3F4800 + MSM_FB_DSUB_PMEM_ADDER, 4096)
#elif defined(CONFIG_FB_MSM_TVOUT)
#define MSM_FB_SIZE roundup(MSM_FB_PRIM_BUF_SIZE + 0x195000 + MSM_FB_DSUB_PMEM_ADDER, 4096)
#else 
#define MSM_FB_SIZE roundup(MSM_FB_PRIM_BUF_SIZE + MSM_FB_DSUB_PMEM_ADDER, 4096)
#endif 
#ifdef CONFIG_MSM_IOMMU
#define MSM_PMEM_SF_SIZE 0x8000000
#else
#define MSM_PMEM_SF_SIZE 0x8000000 
#endif
#define MSM_OVERLAY_BLT_SIZE   roundup(960 * ALIGN(540, 32) * 3 * 2, 4096)

#define MSM_PMEM_KERNEL_EBI1_SIZE  0x600000 
#define MSM_PMEM_ADSP_SIZE	0x239C000
#define MSM_PMEM_ADSP2_SIZE 0x1700000
#define MSM_PMEM_AUDIO_SIZE	0x4CF000

#define MSM_PMEM_SF_BASE		(0x70000000 - MSM_PMEM_SF_SIZE)
#define MSM_PMEM_ADSP_BASE		(MSM_PMEM_SF_BASE - MSM_PMEM_ADSP_SIZE)
#define MSM_FB_BASE				(0x40400000)
#define MSM_PMEM_AUDIO_BASE		(0x46400000)


#define MSM_SMI_BASE          0x38000000
#define MSM_SMI_SIZE          0x4000000

#define KERNEL_SMI_BASE       (MSM_SMI_BASE)
#define KERNEL_SMI_SIZE       0x400000

#define USER_SMI_BASE         (KERNEL_SMI_BASE + KERNEL_SMI_SIZE)
#define USER_SMI_SIZE         (MSM_SMI_SIZE - KERNEL_SMI_SIZE)
#define MSM_PMEM_SMIPOOL_BASE USER_SMI_BASE
#define MSM_PMEM_SMIPOOL_SIZE USER_SMI_SIZE

#ifdef CONFIG_MSM_MULTIMEDIA_USE_ION
#define MSM_ION_SF_SIZE       0x5000000 /* 80 Mbytes */
#define MSM_ION_CAMERA_SIZE   MSM_PMEM_ADSP_SIZE
#define MSM_ION_MM_FW_SIZE    0x200000 /* (2MB) */  
#define MSM_ION_MM_SIZE	      0x3600000 /* (54MB) */ 
#define MSM_ION_MFC_SIZE      0x1000000  
#define MSM_ION_WB_SIZE       0x1E00000 /* 30MB */

#ifdef CONFIG_TZCOM
#define MSM_ION_QSECOM_SIZE   MSM_PMEM_KERNEL_EBI1_SIZE
#ifdef CONFIG_MSM_IOMMU
#define MSM_ION_HEAP_NUM      8
#else
#define MSM_ION_HEAP_NUM      9
#endif
#else
#ifdef CONFIG_MSM_IOMMU
#define MSM_ION_HEAP_NUM      7
#else
#define MSM_ION_HEAP_NUM      8
#endif
#endif

#define MSM_ION_WB_BASE       (0x40400000)
#define MSM_ION_MFC_BASE      (0x74B00000)
#define MSM_ION_AUDIO_BASE    (0x7FB00000)

#else 
#define MSM_ION_HEAP_NUM      1
#endif

#define PHY_BASE_ADDR1  0x48000000
#define SIZE_ADDR1      0x23000000


#define SHOOTER_GPIO_SW_LCM_3D       (64)
#define SHOOTER_GPIO_SW_LCM_2D       (68)
#define SHOOTER_GPIO_KEY_VOL_DOWN    (103)
#define SHOOTER_GPIO_KEY_VOL_UP      (104)
#define SHOOTER_GPIO_KEY_CAM_STEP2   (115)
#define SHOOTER_GPIO_KEY_CAM_STEP1   (123)
#define SHOOTER_GPIO_KEY_POWER       (125)

#define SHOOTER_GPIO_MBAT_IN            (61)
#define SHOOTER_GPIO_CHG_INT		(126)

#define SHOOTER_GPIO_WIFI_IRQ              (46)
#define SHOOTER_GPIO_WIFI_SHUTDOWN_N       (96)

#define SHOOTER_GPIO_WIMAX_UART_SIN        (41)
#define SHOOTER_GPIO_WIMAX_UART_SOUT       (42)
#define SHOOTER_GPIO_V_WIMAX_1V2_RF_EN     (43)
#define SHOOTER_GPIO_WIMAX_EXT_RST         (49)
#define SHOOTER_GPIO_V_WIMAX_DVDD_EN       (94)
#define SHOOTER_GPIO_V_WIMAX_PVDD_EN       (105)
#define SHOOTER_GPIO_WIMAX_SDIO_D0         (143)
#define SHOOTER_GPIO_WIMAX_SDIO_D1         (144)
#define SHOOTER_GPIO_WIMAX_SDIO_D2         (145)
#define SHOOTER_GPIO_WIMAX_SDIO_D3         (146)
#define SHOOTER_GPIO_WIMAX_SDIO_CMD        (151)
#define SHOOTER_GPIO_WIMAX_SDIO_CLK_CPU    (152)
#define SHOOTER_GPIO_CPU_WIMAX_SW          (156)
#define SHOOTER_GPIO_CPU_WIMAX_UART_EN     (157)


#define SHOOTER_SENSOR_I2C_SDA		(72)
#define SHOOTER_SENSOR_I2C_SCL		(73)
#define SHOOTER_GYRO_INT               (127)
#define SHOOTER_ECOMPASS_INT           (128)
#define SHOOTER_GSENSOR_INT           (129)


#define SHOOTER_TP_I2C_SDA           (51)
#define SHOOTER_TP_I2C_SCL           (52)
#define SHOOTER_TP_ATT_N             (65)
#define SHOOTER_TP_ATT_N_XC          (57)

#define GPIO_LCD_TE	28
#define GPIO_LCM_ID	50
#define GPIO_LCM_RST_N	66

#define SHOOTER_AUD_CODEC_RST        (67)
#define SHOOTER_AUD_CDC_LDO_SEL      (116)
#define SHOOTER_AUD_MIC_SEL        PMGPIO(14)
#define SHOOTER_AUD_SPK_ENO        PMGPIO(19)
#define SHOOTER_AUD_HANDSET_ENO    PMGPIO(18)

#define SHOOTER_GPIO_BT_HOST_WAKE      (45)
#define SHOOTER_GPIO_BT_UART1_TX       (53)
#define SHOOTER_GPIO_BT_UART1_RX       (54)
#define SHOOTER_GPIO_BT_UART1_CTS      (55)
#define SHOOTER_GPIO_BT_UART1_RTS      (56)
#define SHOOTER_GPIO_BT_SHUTDOWN_N     (100)
#define SHOOTER_GPIO_BT_CHIP_WAKE      (130)
#define SHOOTER_GPIO_BT_RESET_N        (142)

#define SHOOTER_GPIO_MHL_WAKE_UP        (62)
#define SHOOTER_GPIO_USB_ID        (63)
#define SHOOTER_GPIO_MHL_RESET        (70)
#define SHOOTER_GPIO_MHL_INT		(71)
#define SHOOTER_GPIO_MHL_USB_EN         (139)
#define SHOOTER_GPIO_MHL_USB_SW        (99)

#define SHOOTER_GENERAL_I2C_SDA		(59)
#define SHOOTER_GENERAL_I2C_SCL		(60)

#define SHOOTER_FLASH_EN             (29)
#define SHOOTER_TORCH_EN             (30)

#define SHOOTER_GPIO_AUD_HP_DET        (31)

#define SHOOTER_SPI_DO                 (33)
#define SHOOTER_SPI_DI                 (34)
#define SHOOTER_SPI_CS                 (35)
#define SHOOTER_SPI_CLK                (36)

#define SHOOTER_SP3D_SPI_DO                 (37)
#define SHOOTER_SP3D_SPI_DI                 (38)
#define SHOOTER_SP3D_SPI_CS                 (39)
#define SHOOTER_SP3D_SPI_CLK                (40)

#define SHOOTER_CAM_I2C_SDA           (47)
#define SHOOTER_CAM_I2C_SCL           (48)

#define SHOOTER_SP3D_GATE              (107)
#define SHOOTER_SP3D_CORE_GATE         (58)
#define SHOOTER_SP3D_SYS_RST           (102)
#define SHOOTER_SP3D_PDX               (137)

#define SHOOTER_S5K4E1_PD				(137)
#define SHOOTER_S5K4E1_INTB				(102)
#define SHOOTER_S5K4E1_VCM_PD			(58)

#define SHOOTER_SP3D_MCLK		(32)
#define SHOOTER_WEBCAM_STB		(140)
#define SHOOTER_WEBCAM_RST		(138)
#define SHOOTER_CAM_SEL			(141)

#define SHOOTER_CTL_3D_1		(131)
#define SHOOTER_CTL_3D_2		(132)
#define SHOOTER_CTL_3D_3		(133)
#define SHOOTER_CTL_3D_4		(134)
#define SHOOTER_LCM_3D_PDz		(135)


#define PMGPIO(x) (x-1)
#define SHOOTER_3DLCM_PD           PMGPIO(20)
#define SHOOTER_AUD_QTR_RESET      PMGPIO(21)
#define SHOOTER_TP_RST             PMGPIO(23)
#define SHOOTER_GREEN_LED          PMGPIO(24)
#define SHOOTER_AMBER_LED          PMGPIO(25)
#define SHOOTER_3DCLK              PMGPIO(26)
#define SHOOTER_AUD_MIC_SEL        PMGPIO(14)
#define SHOOTER_CHG_STAT	   PMGPIO(33)
#define SHOOTER_SDC3_DET           PMGPIO(34)
#define SHOOTER_PLS_INT            PMGPIO(22)
#define SHOOTER_AUD_REMO_PRES      PMGPIO(37)
#define SHOOTER_AUD_REMO_EN	   PMGPIO(15)
#define SHOOTER_WIFI_BT_SLEEP_CLK  PMGPIO(38)
#define SHOOTER_TORCH_SET1         PMGPIO(32)
#define SHOOTER_TORCH_SET2         PMGPIO(31)
#define SHOOTER_WIMAX_HOST_WAKEUP  PMGPIO(17)
#define SHOOTER_WIMAX_DEBUG12      PMGPIO(16)
#define SHOOTER_WIMAX_DEBUG14_XA   PMGPIO(28)
#define SHOOTER_WIMAX_DEBUG15_XA   PMGPIO(30)
#define SHOOTER_WIMAX_DEBUG14      PMGPIO(35)
#define SHOOTER_WIMAX_DEBUG15      PMGPIO(36)

extern int panel_type;

int shooter_mdp_gamma(void);

int __init shooter_init_mmc(void);
void __init shooter_audio_init(void);
int __init shooter_init_keypad(void);
int __init shooter_wifi_init(void);
int __init shooter_init_panel(struct resource *res, size_t size);
void shooter_init_gpiomux(void);

#endif

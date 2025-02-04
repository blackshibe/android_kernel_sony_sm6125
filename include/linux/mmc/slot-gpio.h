/*
 * Generic GPIO card-detect helper header
 *
 * Copyright (C) 2011, Guennadi Liakhovetski <g.liakhovetski@gmx.de>
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License version 2 as
 * published by the Free Software Foundation.
 */
/*
 * NOTE: This file has been modified by Sony Mobile Communications Inc.
 * Modifications are Copyright (c) 2016 Sony Mobile Communications Inc,
 * and licensed under the license of the file.
 */

#ifndef MMC_SLOT_GPIO_H
#define MMC_SLOT_GPIO_H

#include <linux/types.h>
#include <linux/irqreturn.h>

struct mmc_host;

int mmc_gpio_get_ro(struct mmc_host *host);
int mmc_gpio_request_ro(struct mmc_host *host, unsigned int gpio);

int mmc_gpio_get_cd(struct mmc_host *host);
int mmc_gpio_request_cd(struct mmc_host *host, unsigned int gpio,
			unsigned int debounce);

int mmc_gpiod_request_cd(struct mmc_host *host, const char *con_id,
			 unsigned int idx, bool override_active_level,
			 unsigned int debounce, bool *gpio_invert);
int mmc_gpiod_request_ro(struct mmc_host *host, const char *con_id,
			 unsigned int idx, bool override_active_level,
			 unsigned int debounce, bool *gpio_invert);
void mmc_gpio_set_cd_isr(struct mmc_host *host,
			 irqreturn_t (*isr)(int irq, void *dev_id));
void mmc_gpiod_free_cd_irq(struct mmc_host *host);
void mmc_gpiod_restore_cd_irq(struct mmc_host *host);
void mmc_gpiod_request_cd_irq(struct mmc_host *host);
bool mmc_can_gpio_cd(struct mmc_host *host);
void mmc_register_extcon(struct mmc_host *host);
void mmc_unregister_extcon(struct mmc_host *host);

void mmc_gpio_init_uim2(struct mmc_host *host, unsigned int gpio);
void mmc_gpio_set_uim2_en(struct mmc_host *host, int value);
void mmc_gpio_tray_close_set_uim2(struct mmc_host *host, int value);
#endif

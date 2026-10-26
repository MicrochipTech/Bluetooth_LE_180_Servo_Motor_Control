/*
 * Copyright (c) 2025 Microchip Technology Inc.
 *
 * SPDX-License-Identifier: Apache-2.0
 */

#ifndef APP_SERVO_MOTOR_180_H
#define APP_SERVO_MOTOR_180_H

#include <zephyr/types.h>
#include <zephyr/bluetooth/conn.h>

/* Protocol Constants */
#define SERVO_MOTOR_OPCODE              0x8E
#define SERVO_MOTOR_SERVICE_DATA        0xFFE1

/* Fixed servo type for this project */
#define SERVO_TYPE_180                  0x00
#define SERVO_MOTOR_TYPE                SERVO_TYPE_180

/* Control Request IDs (App -> Device) */
#define SERVO_CMD_UI_UPDATE_REQ         0xA1
#define SERVO_CMD_SLIDER_SET            0xA2
#define SERVO_CMD_FIXED_POSITION_SET    0xA3

/* Data Response IDs (Device -> App) */
#define SERVO_RSP_UI_UPDATE             0xB1
#define SERVO_RSP_SLIDER_SET            0xB2
#define SERVO_RSP_FIXED_POSITION_SET    0xB3

/* Notification IDs (Device -> App) */
#define SERVO_NTF_SLIDER                0xC2
#define SERVO_NTF_FIXED_POSITION        0xC3

/* Acknowledgment Response IDs */
#define SERVO_ACK_UI_UPDATE             0xD1
#define SERVO_ACK_SLIDER_SET            0xD2
#define SERVO_ACK_FIXED_POSITION_SET    0xD3

/* Fixed Position Values (180 servo) */
#define SERVO_POS_0_DEG                 0x00
#define SERVO_POS_90_DEG                0x5A
#define SERVO_POS_180_DEG               0xB4

int app_servo_motor_ble_init(void);

int app_servo_motor_ble_handle_cmd(struct bt_conn *conn, uint8_t opcode,
                                   const uint8_t *payload, uint16_t payload_len);

int app_servo_motor_ble_send_ui_update_response(struct bt_conn *conn);

int app_servo_motor_ble_send_slider_response(struct bt_conn *conn, uint16_t slider_value);

int app_servo_motor_ble_send_fixed_position_response(struct bt_conn *conn, uint8_t position);

int app_servo_motor_ble_send_slider_notify(struct bt_conn *conn, uint16_t slider_value);

int app_servo_motor_ble_send_fixed_position_notify(struct bt_conn *conn, uint8_t position);

int app_servo_motor_ble_send_ack(struct bt_conn *conn, uint8_t ack_id);

#endif /* APP_SERVO_MOTOR_180_H */

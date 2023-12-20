/*******************************************************************************
* \file xensiv_radar_gestures.h
*
* \brief
* Provides API declarations for the XENSIV(TM) RADAR presence detection library.
*
********************************************************************************
* \copyright
* (c) 2023 Infineon Technologies AG.
*
* SPDX-License-Identifier: Apache-2.0
*
* Licensed under the Apache License, Version 2.0 (the "License");
* you may not use this file except in compliance with the License.
* You may obtain a copy of the License at
*
*     http://www.apache.org/licenses/LICENSE-2.0
*
* Unless required by applicable law or agreed to in writing, software
* distributed under the License is distributed on an "AS IS" BASIS,
* WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
* See the License for the specific language governing permissions and
* limitations under the License.
*******************************************************************************/

/**
 * \addtogroup group_board_libs XENSIV(TM) Radar Gestures Recognition
 * \{
 */
#ifndef XENSIV_RADAR_GESTURES_H_
#define XENSIV_RADAR_GESTURES_H_

/**
 * @brief Structure representing the results of an inference.
 *
 */
typedef struct inference_results_t
{
    /*! Index representing the recognized gesture. */
    int idx;

    /*! Level of confidence for the recognized gesture. */
    float32_t score;
} inference_results_t;


/** \cond INTERNAL */
/** Threshold for gesture recognition. */
extern float32_t gesture_detection_threshold;
/** \endcond */

/******************************* Function prototypes *************************************/

#ifdef __cplusplus
extern "C" {
#endif

/**
 * @brief Initializes XENSIV(TM) Radar Gestures recognition algorithmic kernel.
 *
 * @return void
 */
void gestures_init();


/** @brief Run gesture recognition algorithmic kernel
 *
 * @param[in] buffer_ptr       Pointer to radar data
 * @param[out] results         Pointer to inference as defined by \ref inference_results_t
 *
 * @return void
 */
void gestures_run(float32_t* buffer_ptr, inference_results_t* results);


/**
 * @brief De-initializes XENSIV(TM) Radar Gestures recognition algorithmic kernel.
 *
 * @return void
 */
void gestures_deinit();

/**
 * @brief Retrieve all detection indices
 *
 * @return void
 */
float* get_logits();

/** \} group_board_libs */

#ifdef __cplusplus
}
#endif

#endif // XENSIV_RADAR_GESTURES_H_

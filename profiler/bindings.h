#include <cstdarg>
#include <cstdint>
#include <cstdlib>
#include <ostream>
#include <new>

/**
 * @brief Set of available options to select ADC's channel.
 */
enum class AdcChannel {
  Ch0,
  Ch1,
  Ch2,
  Ch3,
};

/**
 * @brief Set of available options to select PWM's channel.
 */
enum class PwmChannel {
  Ch1,
  Ch2,
  Ch3,
  Ch4,
  Ch5,
  Ch6,
  Ch7,
  Ch8,
  Ch9,
  Ch10,
  Ch11,
  Ch12,
  Ch13,
  Ch14,
  Ch15,
  Ch16,
  All,
};

/**
 * @brief Set of options to control navigator's LEDs.
 */
enum class UserLed {
  Led1,
  Led2,
  Led3,
};

/**
 * @brief Encapsulates the value of ADC's four channels.
 */
struct ADCData {
  float channel[4];
};

/**
 * @brief The AxisData encapsulate values for the x, y, and z axes.
 */
struct AxisData {
  float x;
  float y;
  float z;
};

extern "C" {

/**
 * @brief Initialize the navigator module with default settings.
 */
void init();

/**
 * @brief Runs some tests on available sensors and returns the result.
 * @return true if the sensors are OK.
 */
bool self_test();

/**
 * @brief Sets the selected navigator LED output.
 * @param select The LED to be selected.
 * @param state The desired state of the LED. True turns the LED on.
 */
void set_led(UserLed select, bool state);

/**
 * @brief Gets the state of the selected LED.
 * @param select The LED to be selected.
 * @return true if the LED is on.
 */
bool get_led(UserLed select);

/**
 * @brief Toggles the selected LED's state.
 * @param select The LED to be selected.
 */
void set_led_toggle(UserLed select);

/**
 * @brief Set the state for all LEDs.
 * @param state Desired state for all LEDs. True turns them on.
 */
void set_led_all(bool state);

void set_neopixel(const uint8_t (*rgb_array)[3], uintptr_t length);

/**
 * @brief Reads all ADC channels.
 * @return Measurements for all ADC channels in Volts.
 */
ADCData read_adc_all();

/**
 * @brief Reads the selected ADC channel.
 * @param channel The ADC channel to read.
 * @return Measurement for the selected ADC channel in Volts.
 */
float read_adc(AdcChannel channel);

/**
 * @brief Reads the pressure.
 * @return Measurement in kPa.
 */
float read_pressure();

/**
 * @brief Reads the temperature.
 * @return Measurement in degrees Celsius.
 */
float read_temp();

/**
 * @brief Reads the magnetometer data.
 * @return Measurements for x, y, z axes in micro-Teslas.
 */
AxisData read_mag();

/**
 * @brief Reads accelerometer data.
 * @return Measurements for x, y, z axes in m/s^2.
 */
AxisData read_accel();

/**
 * @brief Reads gyroscope data.
 * @return Measurements for x, y, z axes in rad/s.
 */
AxisData read_gyro();

/**
 * @brief Enables or disables the PWM IC.
 * @param state Desired state for the PWM output. True enables it.
 */
void pwm_enable(bool state);

/**
 * @brief Sets the PWM frequency based on a given prescaler value.
 * @param value The prescaler value (3..255).
 */
void set_pwm_freq_prescale(uint8_t value);

/**
 * @brief Sets the PWM frequency in Hertz.
 * @param freq The desired frequency in Hz (24..1526).
 */
void set_pwm_freq_hz(float freq);

/**
 * @brief Sets the Duty Cycle of the selected PWM channel.
 * @param channel The PWM channel to set.
 * @param value The desired Duty Cycle value.
 */
void set_pwm_channel_value(PwmChannel channel, uint16_t value);

/**
 * @brief Sets the Duty Cycle of multiples PWM channels.
 * @param channels A list of PWM channels.
 * @param value The desired Duty Cycle value.
 * @param length Size of the list.
 */
void set_pwm_channels_value(const PwmChannel *channels, uint16_t value, uintptr_t length);

/**
 * @brief Sets the Duty Cycle of multiples PWM channels.
 * @param channels A list of PWM channels.
 * @param values A list of desired Duty Cycles values per channel (should have the same size as channels).
 * @param length Size of the list.
 */
void set_pwm_channels_values(const PwmChannel *channels, const uint16_t *values, uintptr_t length);

} // extern "C"
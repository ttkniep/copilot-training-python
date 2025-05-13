class CustomSerialTemperatureSensor:
    COMMAND_GET_TEMPERATURE_CELSIUS = "GTC\n"
    COMMAND_GET_TEMPERATURE_FAHRENHEIT = "GTF\n"
    COMMAND_GET_DEVICE_ID = "GID\n"

    def __init__(self, serial_port):
        self.serial_port = serial_port

    def read_temperature(self, unit="Celsius"):
        """Reads temperature data from the serial port."""
        command = (self.COMMAND_GET_TEMPERATURE_CELSIUS
                   if unit == "Celsius" else self.COMMAND_GET_TEMPERATURE_FAHRENHEIT)
        response = self.run_command(command)
        try:
            return float(response)
        except ValueError:
            raise Exception("Invalid temperature data received.")

    def read_device_id(self):
        """TODO: implement this method."""
        return ""

    def run_command(self, command):
        """Sends a command to the serial port and returns the response."""
        self.serial_port.write(command)
        response = self.serial_port.read()
        if not response:
            raise Exception("No response received from the device.")
        return response.strip()

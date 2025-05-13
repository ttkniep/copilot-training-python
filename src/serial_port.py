class SerialPort:
    def __init__(self, port_name):
        self.port_name = port_name

    def open(self):
        """Opens the serial port."""
        print(f"Opening serial port: {self.port_name}")

    def close(self):
        """Closes the serial port."""
        print(f"Closing serial port: {self.port_name}")

    def read(self):
        """Simulates reading data from the serial port."""
        # Replace this with actual serial port reading logic
        return "Simulated response"

    def write(self, command):
        """Simulates writing data to the serial port."""
        print(f"Writing to serial port: {command}")


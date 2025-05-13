import unittest
from unittest.mock import MagicMock
from src.custom_serial_temperature_sensor import CustomSerialTemperatureSensor

class TestCustomSerialTemperatureSensor(unittest.TestCase):
    def setUp(self):
        self.mock_serial_port = MagicMock()
        self.sensor = CustomSerialTemperatureSensor(self.mock_serial_port)

    def test_read_temperature_valid(self):
        self.mock_serial_port.read.return_value = "25.5"  # Mocking read method
        command = "GTC\n"
        temperature = self.sensor.read_temperature()
        self.assertEqual(temperature, 25.5)
        self.mock_serial_port.write.assert_called_once_with(command)

    def test_read_temperature_invalid(self):
        self.mock_serial_port.read.return_value = "invalid"  # Mocking read method
        with self.assertRaises(Exception) as context:
            self.sensor.read_temperature()
        self.assertEqual(str(context.exception), "Invalid temperature data received.")

if __name__ == "__main__":
    unittest.main()

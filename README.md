# Copilot Training Sample Code (Python Version)

## Prerequisites
- Python 3.8 or later
- Recommended: Virtual environment (e.g., `venv` or `virtualenv`)

## Setup Instructions
1. Clone the repository:
   ```bash
   git clone <repository-url>
   cd copilot-training-python
   ```

2. Create and activate a virtual environment:
   ```bash
   python3 -m venv venv
   source venv/bin/activate  # On Windows: venv\Scripts\activate
   ```

3. Install dependencies:
   ```bash
   pip install -r requirements.txt
   ```

4. Run the tests:
   ```bash
   python -m unittest discover tests
   ```

## Project Structure
- `src/`: Contains the implementation of the temperature sensor and serial port.
- `tests/`: Contains unit tests for the project.

## Running the Application
To use the `CustomSerialTemperatureSensor`, import it in your Python script and provide a `SerialPort` instance.

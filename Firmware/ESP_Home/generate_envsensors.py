# generate_envsensors.py
template = """esphome:
  name: {name}
  friendly_name: {friendly}

esp32:
  board: esp32-s2-saola-1
  framework:
    type: esp-idf

logger:

api:
  password: "1"

ota:
  - platform: esphome
    password: "1"

wifi:
  ssid: "IoT"
  password: "InternetOfThings"

captive_portal:

i2c:
  sda: 33
  scl: 35
  scan: true

sensor:
  - platform: sht3xd
    temperature:
      name: "SHT3x Temperature"
    humidity:
      name: "SHT3x Humidity"
    address: 0x44
    update_interval: 10s
"""

# Number of files you want to generate
count = 40

for i in range(1, count + 1):
    name = f"envsensor{i}"
    friendly = f"envSensor{i}"
    filename = f"{name}.yaml"

    with open(filename, "w", encoding="utf-8") as f:
        f.write(template.format(name=name, friendly=friendly))

    print(f"✅ Created {filename}")

print(f"\nAll {count} YAML files generated successfully!")

# LIS3DH IMU sensor app example

## Introduction

This app shows an implementation of LIS3DH sensor using an I2C handler for `thread-safe` communication.

## Requirements

Get `lis3dh` lib to `components` folder.
```
git clone https://github.com/eavelardev/esp-comp-lis3dh.git lis3dh
```

Get `i2c-bus` component dependency from [eavelardev/esp-comp-i2c-bus](https://github.com/eavelardev/esp-comp-i2c-bus)
```
git clone https://github.com/eavelardev/esp-comp-i2c-bus.git i2c-bus
```

## Build and Flash the app

```
idf.py build 
idf.py -p (PORT) flash
```
Output
```
accX: 3.177355 accY: -5.413271 accZ: -7.766867
accX: 6.158576 accY: -5.923216 accZ: -6.590069
accX: 6.668522 accY: -6.040896 accZ: -4.667965
accX: 8.276813 accY: -4.589512 accZ: 2.824315
accX: 4.275699 accY: -2.353596 accZ: 8.394492
accX: 8.982892 accY: -3.687300 accZ: 2.745862
```

This app was also tested in PlatformIO, just put the code in the right place. In this case you don't need to use `idf.py` commands.

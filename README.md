SparkCore.rgbled
================

Control 3 LED over the NET attached to a SparkCore. The LED are on pin A4, A5 and A6. 


Example:
  curl https://api.spark.io/v1/devices/0123456789abcdef01234567/led \
  -d access_token=1234123412341234123412341234123412341234 \
  -d params=1,100

The params are (1-3),(0-255)

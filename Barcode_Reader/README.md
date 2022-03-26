# Barcode Reader
A barcode consists of 12 data frames with a guard frame on each side, to help locate a barcode
within an image, for easier processing. This program assumes each guard frame will be the three
binary bits: `101`.

Each of the 12 data frames excode a number between 0-9 which can be used to uniquely identitfy
each barcode.

<img src = "https://static.au.edusercontent.com/files/KvL5qk8AF7ysh19fpbWud2Gy" alt="barcode image">
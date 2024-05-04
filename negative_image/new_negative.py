from PIL import Image

# Load gambar
img = Image.open("Lenna_(test_image).png")

# Konversi ke mode RGB jika tidak dalam mode itu
if img.mode != "RGB":
    img = img.convert("RGB")

# Mengambil ukuran gambar
width, height = img.size

# Membuat objek baru untuk menyimpan hasil negatif
negatif_img = Image.new("RGB", (width, height))

# Loop melalui setiap piksel dan ubah nilainya
for y in range(height):
    for x in range(width):
        # Ambil nilai RGB dari piksel
        r, g, b = img.getpixel((x, y))
        
        # Ubah menjadi negatif
        r = 255 - r
        g = 255 - g
        b = 255 - b
        
        # Simpan nilai RGB yang diubah pada gambar negatif
        negatif_img.putpixel((x, y), (r, g, b))

# Simpan gambar negatif
negatif_img.save("gambar_output_negatif.jpg")

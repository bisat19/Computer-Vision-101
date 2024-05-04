from PIL import Image

def buat_negatif(gambar):
    # # Konversi gambar ke mode RGB jika tidak dalam mode itu
    # if gambar.mode != "RGB":
    #     gambar = gambar.convert("RGB")

    # Membuat objek baru untuk menyimpan hasil negatif
    negatif_img = Image.new(gambar.mode, gambar.size)

    # Ambil ukuran gambar
    width, height = gambar.size

    # Loop melalui setiap piksel dan ubah nilainya
    for y in range(height):
        for x in range(width):
            # Ambil nilai piksel
            nilai_pixel = gambar.getpixel((x, y))
            
            # Jika gambar grayscale, maka nilai piksel adalah integer tunggal
            if isinstance(nilai_pixel, int):
                nilai_negatif = 255 - nilai_pixel
            else:
                # Jika gambar RGB, nilai piksel adalah tupel (R, G, B)
                nilai_negatif = tuple(255 - nilai for nilai in nilai_pixel)

            # Simpan nilai piksel yang diubah pada gambar negatif
            negatif_img.putpixel((x, y), nilai_negatif)

    return negatif_img

# Contoh penggunaan
gambar_input = Image.open("Lenna_(test_image).png")
grayscale_image = gambar_input.convert('L')
grayscale_image.save("grayscale_image.jpg")
gambar_negatif = buat_negatif(gambar_input)
gambar_negatif.save("negatif.jpg")
gambar_negatif2 = buat_negatif(grayscale_image)
gambar_negatif2.save("negatif2.jpg")

# Sensör Konfigürasyonu
YRT Aviyonik Departmanı Yazılım Ekibi destek ekip ödevi için hazırlanmıştır.

## Kullanım Talimatları 📝
1. ACCEL_RANGE, BAND_WIDTH ve OPERATION_MODE değerlerini girin. 
2. Kodu çalıştırın.
3. AccConfigValue değerini decimal, hexadecimal ve binary formatlarda göreceksiniz.

## Kod Açıklaması 💻
Kodun en başında ACCEL_RANGE, BAND_WIDTH ve OPERATION_MODE değerleri define ifadesi ile belirlenmiştir.

### Main Fonksiyonu
Main fonksiyonunda ilk olarak gerekli enum ve struct yapıları oluşturuluyor. Daha sonra config adında bir değişkene en başta belirlenen veriler atanıyor ve bu veriler kullanılarak AccConfigValue değeri hesaplnıyor. Son olarak hesaplanan değer decimal, hexadecimal ve binary olarak yazdırılmak üzere ilgili fonksiyonalara parametre olarak veriliyor.

### Decimal Değer Yazdırma Fonksiyonu
Bu fonksiyon yalnızca aldığı parametreyi printf fonksiyonu ile ekrana bastırıyor.

### Hexadecimal Değer Yazdırma Fonksiyonu
Bu fonksiyon da aynı decimal değer yazdırma fonksiyonu gibi yalnızca aldığı parametreyi printf fonksiyonu ile ekrana bastırıyor ancak ufak bir farkla. Bu defa placeholder olarak integer türü veriler için kullanılan %d değil, hexadecimal değerler için kullanılan %x placeholderi kullanılıyor. % ve x işaretleri arasında bulunan 0 ifadesi, çıktı istenen uzunluktan kısa olursa eksik hanelerin 0 ile doldurulmasını; 2 ifadesi ise çıktının uzunluğunu en az 2 yapmayı sağlıyor.

### Binary Değer Yazdırma Fonksiyonu
Bu fonksiyon ilk olarak sonuç adında 8 elemandan oluşan, tüm elemanları sıfır olan bir array oluşturuyor. daha sonra ödev dosyasında açıkladığım decimal değeri binary değere dönüştürme adımlarını kullanarak sonuç arrayini doldurur ve arrayi ekrana bastırıyor.

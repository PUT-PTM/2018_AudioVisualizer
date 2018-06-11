
# Audio Visualizer
**Przedstawienie spektrum odtwarzanej muzyki na lampach nixie za pomocą STM32.**
<img src="https://scontent-waw1-1.xx.fbcdn.net/v/t1.15752-9/35240453_1610562355727098_3018999595452596224_n.png?_nc_cat=0&oh=07fd6268e9ff539c5768447c8ce7ff9b&oe=5BC332F9" width="750" height="350" alt="Pierwsze uruchomienie układu">

## Opis projektu
Projekt został wykonany z użyciem mikrokontrolera STM32F4DISCOVERY, lamp Nixie in-9 i układów wykonanych przez nas: 
zasilającego (transformator, prostownik, stabilizator) oraz płytki drukowanej.

## Opis działania
* zasilanie:  
Prąd przemienny 230V zostaje doprowadzony kablem do transformatora, który obniża jego napięcie do 160V. Następnie przy użyciu prostownika,
zamieniany jest na prąd stały +-110V i stabilizowany za pomocą kondensatorów.
* układ obliczeniowy:  
Sygnał audio stereo zostaje wczytany do mikrokontrolera za pomocą 2 kanałów ADC, po czym zostają połączone w uśredniony wynik. Następuje
zebranie próbek sygnału i przekazanie je do szybkiej transformaty Fouriera (RFFT). Otrzymany wynik przekształcenia, za pomocą odpowiednich
wag, zostaje skompresowane do ilości wyjść i odpowiednio wyskalowane. 
* zasada kontrolowania:  
Anody lamp Nixie zostają podłączone do zasilania, a katody do tranzystorów. Gotowy wynik tranformaty zostaje przekazany na odpowiednie piny PWM,
które połączone są z tranzystorami. Możliwość zmiany wypełnienia modulacji szerokości impulsu (PWM) oraz "przełożenie" 3V z płytki STM32F4
na dużo wyższe napięcie za pomoca tranzystorów sprawiają, że można z sukcesem zarządzać poziomem wypełnienia konkretnej lampy.

## Do zrobienia
* zamontowanie wszystkich 18 lamp
* ustalenie otrzymanej kolejności lamp
* sprawdzenie poprawności działania wszystkich timerów i PWM
* dostrojenie parametrów transformaty Fouriera do lamp

## Autorzy
* [Mikołaj Walkowiak](https://github.com/mikolaj-walkowiak)
* [Paweł Przybyłowski](https://github.com/stfoorca)
* [Bartosz Ptak](https://github.com/bartoszptak/)

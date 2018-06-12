
# Audio Visualizer
**Przedstawienie spektrum odtwarzanej muzyki na lampach nixie za pomocą STM32.**
<img src="https://scontent-waw1-1.xx.fbcdn.net/v/t1.15752-9/35240453_1610562355727098_3018999595452596224_n.png?_nc_cat=0&oh=07fd6268e9ff539c5768447c8ce7ff9b&oe=5BC332F9" width="750" height="350" alt="Pierwsze uruchomienie układu">

## Opis projektu
Projekt został wykonany z użyciem mikrokontrolera STM32F4DISCOVERY, lamp Nixie in-9 i układów wykonanych przez nas: 
zasilającego (transformator, prostownik, stabilizator) oraz płytki drukowanej.

## Opis działania
* zasilanie:  
Prąd przemienny 230V zostaje doprowadzony kablem do transformatora, który obniża jego napięcie do ~130V. Następnie przy użyciu prostownika, zamieniany jest on na prąd stały ~180V i stabilizowany za pomocą kondensatorów. Wykracza to poza specyfikacje lamp, jednak układ sterowania przejmuje na siebie część napięcia, więc jedynym skutkiem ubocznym jest nagrzanie się tranzystorów
* układ obliczeniowy:  
Sygnał audio stereo zostaje wczytany do mikrokontrolera za pomocą 2 kanałów ADC, po czym zostają połączone w uśredniony wynik. Następuje
zebranie próbek sygnału i przekazanie ich do szybkiej transformaty Fouriera (RFFT). Otrzymany wynik przekształcenia, za pomocą odpowiednich
wag, zostaje skompresowany do ilości wyjść i odpowiednio wyskalowane. 
* zasada kontrolowania:  
Jak widac na poniższym wykresie wysokośc świecacego neonu w lampie jest powiązana z natężeniem prądu:
<img src= "https://i.imgur.com/2FdSKM0.png">

Sterowanie natężeniem można osiągnąć za pomocą tak zwanego <i> current sink </i>
<img src="https://i.imgur.com/0xkUhvV.png">


<img src="https://i.imgur.com/db0xtqB.png">
                                                                  
Jest to układ bardzo prosty, jednak niestety napięcia wymagane do obsługi tego układu dwukrotnie przekraczają możliwości płytki STM32F4.
Jest również wrażliwy na zmiany temperatury tranzystora (kilka milimetrów, ale perfekcjonizm to nasze drugie imię), oraz Vmin nie mogłoby być = 0, co również byłoby nieintuicyjne.
Z tego powodu nasz układ posługuje się poniższym układem:


<img src="https://i.imgur.com/v6mt7dC.png">

w którym to natężenie płynące przez lamę jest równe `I = V(in)/R`

Anody lamp Nixie zostają podłączone do zasilania, a katody do tranzystorów. Gotowy wynik tranformaty zostaje przekazany na odpowiednie piny PWM, które połączone są z tranzystorami. Możliwość zmiany wypełnienia modulacji szerokości impulsu (PWM) przekłada się na sterowanie napieciem w zakresie 0-3V. Wzmocnienie wzmacniaczem pozwala nam osiągnąć pełny zakres napięć wymaganych do obsługi lamp.

## Ustawienia projektu w System Workbench for STM32
1. zmiana FPU_PRESENT na 0 w stm32f4xx.h:
     `#define __FPU_PRESENT             0`
2. Z menu SystemWorkbench Project -> Properties -> C/C++ Build -> MCU Settings zmienić:  
     a) Floating-point hardware na "No unit"  
     b) Floating-point ABI na "soft"
3. Z menu SystemWorkbench Project -> Properties -> C/C++ General -> Path and Symbols -> Symbols dodać:
    `ARM_MATH_CM4`
    
## Do zrobienia
* zamontowanie wszystkich 18 lamp
* ustalenie otrzymanej kolejności lamp
* sprawdzenie poprawności działania wszystkich timerów i PWM
* dostrojenie parametrów transformaty Fouriera do lamp

## Autorzy
* [Mikołaj Walkowiak](https://github.com/mikolaj-walkowiak)
* [Paweł Przybyłowski](https://github.com/stfoorca)
* [Bartosz Ptak](https://github.com/bartoszptak/)  
  
**Projekt został wykonany w ramach Podstaw Technik Mikroprocesorowych - przedmiotu prowadzonego przez Instytut Automatyki i Informatyki Politechniki Poznańskiej.  
Opiekun: Marek Kraft**

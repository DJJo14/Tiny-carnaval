


# Tiny carnaval
Dit project is bedoelt om verschillende dingen aan te sturen. Om deze bijvoorbeeld lampen te laten knipperen. Het is zo gemaakt dat deze meerdere toepassingen kan hebben. Bijvoorbeeld gewoon knipperende lichten of het na bootsen van een zwaailicht. En daarna hergebruikt te worden, om weer wat anders te maken.
## Voeding
Het boardje dient aangesloten te worden op een auto accu van 12V (24V gaat hij stuk en 6V werkt hij mogelijk niet), een andere 12v voeding is ook mogelijk (bijvoorbeeld een 12v adapter of de 12v van een oude PC voeding).
Voor de voeding heeft het boardje de aansluiting aan de zij kant zitten. een + (rode draad) en - (zwarte draad). **Draai dit niet om, want dan gaat hij stuk, en daar bij ook mogelijk de accu.**
## Uitgangen
Het printje heeft 4 uitgangen en zijn genummerd van 0 t/m 3. 
De uitgang wordt geschakeld in de min, (de zwarte draad).
per uitgang is er nog een extra +, (de rode draad).
**LET OP Er is hierbij nog een extra -, deze hoeft niet aangesloten te worden, maar kan snel verwart worden.**
Boven aanzicht, van het boardtje
|  | Min | Uitgang 0 | Plus | Uitgang 1 | Plus | Uitgang 2 | Plus | Uitgang 3 | **Plus** | 
|-|-|-|-|-|-|-|-|-|-
| **Plus** |
| **Min** | |Led 0||Led 1|| Led 2||Led 3 |
| | | **Micro usb** | | Knop |
De schakelende onderdelen zijn geschikt voor 40A bij 12V. 
toch word er aangeraden niet meer dan 16A per gelijkt gelijkertijd aan te hebben, wegens de connectoren en draad dikte.  Kijk naar de verschillende modus, wat van toepassing is.
Er zijn hier door geen extra relays (relais, in het Nederlands) nodig. In sommige modus is het zelf af te raden om deze te gebruiken vanwege het snelle schakelen.
**Tijdens de configuratie is het ook af te raden om de uitgangen aan te sluiten.**
## Opstarten
nadat de spanning op het boardtje staat, duurt het minimaal 8 seconden voordat hij is opgestart. Tijdens het opstarten staat alleen uitgang 3 aan. 
**Sluit NIET de usb poort aan als er zware lampen zijn aangesloten, uitgang 3 kan bij het opstarten gaan knipperen.**
## Configureren
Configureren kan door middel van de print aan te sluiten op usb **of** 12v. Maar bij het gebruik van zware uitgang of het gebruik van relays, is het aan te raden om alleen de USB aan te sluiten.

-	Configureren kan alleen gebeuren, door de knop in drukken tijdens het opstarten. (wacht eerst op de opstart 8 seconden)
-	Daarna kan er door op de knop te drukken (minimaal 300ms), naar de volgende "mode" gegaan. Wacht vervolgens geduldig, want bij sommige modus zal deze lang duren voor dat hij op gang komt.
-	Door de knop in gedrukt te houden voor 5 sec, kan de huidige modus opgeslagen worden. bij opnieuw opstarten zal deze altijd uitgevoerd worden
(de tijd er tussen kan helaas nog niet ingesteld worden, dat zou geprogrammeerd moeten worden.)
## Mode 1
Night rider, een lopend lichtje van links naar recht en weer terug. 
## Mode2
Om en om. uitgang 0 en 2 en daarna 1 en 3.
## Mode 3
als in de brand weer in filmpje : https://www.youtube.com/watch?v=yBFLlOy_Ofc
uitgang 0 en 1, zijn de zwaailichten boven op.
uitgang 2 zijn de koplichten
uitgang 3 zijn de blauwe lichten voor op
## Mode 4
Dobbelsteen, door op het knopje de drukken zal de dobbelsteen gaan rollen. de wilekurigheid wordt bepaalt door de tijd dat het knopje ingedrukt word.
zet de lampen neer zo als hieronder, alle aansluitingen behalve 0, hebben twee lampen. (het nummer kon overeen met het aansluitingsnummer)
|1 |  | 2
|:-:|:-:|:-:|
|3 | 0| 3|
|2| | 1
Bij
-	1 gaan alleen 0 aan.
-	2 gaat alleen 1 aan.
-	3 gaat 2 en 0 aan. 
-	4 gaat 1 en 2 aan.
-	5 gaat 0, 1 en 2 aan.
-	6 gaat 1, 2, en 3 aan.
Met dank aan zakkemble voor inspiratie, deze is in het klein, maar dit kan ook heel groot.
http://blog.zakkemble.net/a-tiny-electronic-dice/


# reddplantene
IoT kurs med introduksjon til ESP8266, Sparkfun Datastreams (Phant) og fuktighetssensor.

Hvis du har moistboard v1.x må du bruke koden fra release v1.0. Koden i masterbranchen er for moistboard v2.x.

# Agenda
- Lodding
- Programmering

# Hardware
- Kretskort
- Utviklingskort "WeMOS D1 Mini", med ESP8266 mikrokontroller
- Fuktsensor
- LED
- Resistor
- Skruterminal
- Dupontkabler
- USB-kabel
- Div.

# Forberedelser

Du må installere et part ting først
 1. Drivere for utviklingskort
 2. Visual Studio Code m/PlatformIo plugin

## Installasjon av drivere
Utviklingskortet programmeres via USB, som krever at du installerer drivere. Drivere for både windows,mac og Linux kan lastes ned her: [driver download](http://www.wch-ic.com/downloads/CH341SER_ZIP.html)

<mark> NB: Installer drivere FØR du kobler ESP8266 utviklingskortet til din PC </mark>

Selve installasjon er litt forskjellig avhengig av hva slags maskin/os du kjører. 

### Windows - CH341SER.EXE
 * Kjør filen CH341SER.EXE 
 * I dialog boksen kjøre "Uninstall" for å sikre at gamle versjoner av deriver installert
 * Kjør deretter Install for å installere

![win-driver-install](images/window-ch340driver-install.png?raw=true)
 
Prøv å koble WeMOS utviklingskortet til datamaskinen din. Du bør høre Windows spille "ding-dong" som tegn på at ny enhet er detektert. Du bør også se driveren under enhetsbehandling som vist under

![win-device-driver](images/window-devices-ch340driver.png?raw=true)


### MacOS - CH341SER_MAC 
Filen inneholder drivere for både Intel- og Apple-silicon. Filen inneholder imidlertid to filer og det er viktig at du installerer riktig fil
 1. CH34xVCPDriver.dmg   for maskiner med OS X 11 og oppover
 2. CH34xVCPDriver.pkg   for maskiner med os eldre enn OS X 11

Installasjon av driver må gjøres som Adminstrator. Du vil få opp et vindu med advarsel! Trykk på "Open System Settings" og velg "Allow" i settings vinduet for å tillate at driveren installeres seg. 

Etter intallasjon kan du sjekke om du har fått en ny device som følger 

```bash 
$ ls -l /dev/tty.w*
crw-rw-rw-  1 root  wheel  0x9000004 Mar 10 19:59 /dev/tty.wchusbserial110
```

### Linux - CH341SER_LINUX.ZIP
Merk:  Ingen driverinstallasjon skal være nødvendig.  

Test følgende: 

```bash 
# Koble utviklings kortet til USB port på linux maskinen din
# Koble fra utviklingskortet 
# bruk dmesg til å se om det ble detektert
$ dmesg
[  xxx] ch341-uart ttyUSB0: ch341-uart converter now disconnected from ttyUSB0
[  xxx] ch341 3-2:1.0: device disconnected
```

Hvis dette ikke funker kan du prøve å patch'e driveren som beskrevet hos [Sparkfun](https://learn.sparkfun.com/tutorials/how-to-install-ch340-drivers/linux)


## Installasjon av Visual Studio Code

### Windows og Mac
https://code.visualstudio.com/download

### Linux 
https://code.visualstudio.com/docs/setup/linux

## Installasjon av PlatformIO plugin i Visual Studio Code

 1. Start visual studio code og gå til Extensions 
 2. Søk opp og installer platformIO
 3. Restart visual studio code

Helt nederst i VSC vinduet finner du nå snarveier for å bygge, laste opp og for å åpne seriell monitor. Det er også en snarvei for å velge hvilket platformIO miljø du vil jobbe med. Et PlatformIO prosjekt kan ha mange miljøer, og i dette prosjektet finnes lesson01-06.  Hvis du lar det stå på Default så bygges alle miljøene når du trykker build, men det vil du ikke. Start med lesson01 og fortsett derfra. 

![vsc-menu](hints/vscodehint.png?raw=true)


# Gjennomføring

Gjør oppgavene du finner i lesson01-06. Eksempel

 * Åpne lesson01.cpp
 * Velg evironment "lesson01" nederst i taskbaren i Visual Studio Code
 * Gjør oppgaven beskrevet i lesson01.cpp
 * Trykk på _build_ knappen i taskbaren
 * Trykk på _upload_ knappen og vent til opplasting er ferdig
 * Trykk på _Serial monitor_ knappen for å se println() output i koden


# Credits

 * Opprinnelig ide: Daniel Holmen
 * Produkt release : Nikhil André Luthra
 * PlatformIO support: Jesper Andersson

## Contact
Contact Nikhil André Luthra if you need to know anything :)
## Prop #2: Bewakingscamera's en IR-Geweer

### Werking:
In elke hoek van de ruimte zijn vier bewakingscamera’s geplaatst. Boven elke camera bevindt zich een lichtje dat knippert onder invloed van het IR-geweer. Er kan maar 1 camera tegelijk knipperen. De spelers moeten met uiterste concentratie richten en schieten met een speciaal geprogrammeerde infraroodzender.

### Componenten:
- 4 IR-ontvangers
- 1 microschakelaar
- 1 Nano Arduino
- 4 camera’s
- 4 Arduino’s (voor ontvangers)

### Uitdagingen/Vragen:
1. De software moet in staat zijn om de bewakingscamera’s individueel uit te schakelen wanneer de juiste frequentie wordt geraakt.
2. De microschakelaar die gebruikt wordt als trigger van het geweer vereist een doordachte integratie met het ontwerp van het geweer.

### Behuizing:
De behuizing wordt geprint met een 3D-printer.

### Programmeren:
Arduino wordt gebruikt om input te ontvangen en verzenden met behulp van C, MQTT.

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>
#include <string.h>

struct Race {
    int numberOfLaps;
    int currentLap;
    char firstPlaceDriverName[20];
    char firstPlaceRaceCarColor[20];
};

struct RaceCar {
    char driverName[20];
    char raceCarColor[20];
    int totalLapTime;
};

void printIntro(void) {
    printf("Welcome to our main event digital race fans! I hope everybody has their snacks because we are about to begin!\n");
}

void printCountDown(void) {
    printf("Racers Ready! In...\n");
    printf("5\n");
    printf("4\n");
    printf("3\n");
    printf("2\n");
    printf("1\n");
    printf("Race!\n");
}

void printFirstPlaceAfterLap(struct Race race) {
    printf("After lap number %d: ", race.currentLap);
    printf("First Place Is: %s in the %s race car!\n",
           race.firstPlaceDriverName, race.firstPlaceRaceCarColor);
}

void printCongratulation(struct Race race) {
    printf("Let's all congratulate %s in the %s race car for an amazing performance!\n",
           race.firstPlaceDriverName, race.firstPlaceRaceCarColor);
    printf("It truly was a great race and everybody have a goodnight!\n");
}

int calculateTimeToCompleteLap(void) {
    int speed = (rand() % 3) + 1;
    int acceleration = (rand() % 3) + 1;
    int nerves = (rand() % 3) + 1;
    return speed + acceleration + nerves;
}

void updateRaceCar(struct RaceCar *raceCar) {
    raceCar->totalLapTime += calculateTimeToCompleteLap();
}

void updateFirstPlace(struct Race *race, struct RaceCar *raceCar1, struct RaceCar *raceCar2) {
    if (raceCar1->totalLapTime <= raceCar2->totalLapTime) {
        strcpy(race->firstPlaceDriverName, raceCar1->driverName);
        strcpy(race->firstPlaceRaceCarColor, raceCar1->raceCarColor);
    } else {
        strcpy(race->firstPlaceDriverName, raceCar2->driverName);
        strcpy(race->firstPlaceRaceCarColor, raceCar2->raceCarColor);
    }
}

void startRace(struct RaceCar *raceCar1, struct RaceCar *raceCar2) {
    struct Race race = {5, 1, "", ""};

    for (int i = 0; i < race.numberOfLaps; i++) {
        updateRaceCar(raceCar1);
        updateRaceCar(raceCar2);
        updateFirstPlace(&race, raceCar1, raceCar2);
        printFirstPlaceAfterLap(race);
        race.currentLap++;
    }
    printCongratulation(race);
}

int main(void) {
    srand(time(0));
    printIntro();
    printCountDown();
    //Racers
    struct RaceCar MarioCar = {"Mario", "Red", 0};
    struct RaceCar LuigiCar = {"Luigi", "Green", 0};
    //start Race
    startRace(&MarioCar, &LuigiCar);

    return 0;
}

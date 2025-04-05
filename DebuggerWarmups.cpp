
#include "DebuggerWarmups.h"
#include "hashcode.h"
#include "error.h"
#include "vector.h"
#include <string>
using namespace std;

/* TODO: Fill this in with your name before reading the story. Otherwise
 * you'll get the wrong story!
 */
const string MyName = "Egor";

namespace {
void theEnd() {
    string text = "THE END!";

    /* Set a breakpoint here. */
    (void) text;
}

void sayHow(int value) {
    string text;
    if (value % 4 == 0) {
        text = "through sheer force of personality.";
    } else if (value % 4 == 1) {
        text = "by setting up an elaborate diversion.";
    } else if (value % 4 == 2) {
        text = "without breaking a sweat.";
    } else {
        text = "for the second time in a week.";
    }

    theEnd();
}

void sayWhatFrom(int value) {
    string text = "from ";
    switch (value % 8) {
    case 0:
        text += "a black hole";
        break;
    case 1:
        text += "kleptomaniacal aliens";
        break;
    case 2:
        text += "a plague of locusts";
        break;
    case 3:
        text += "collective amnesia";
        break;
    case 4:
        text += "certain destruction";
        break;
    case 5:
        text += "a volcanic eruption";
        break;
    case 6:
        text += "the storm of the century";
        break;
    default:
        text += "overzealous ice cream enthusiasts";
        break;
    }

    sayHow(scramble(value));
}

void sayWhatTheyRescued(int value) {
    string text = "saved ";

    Vector<string> options = {
        "the original copy of 'Kubla Khan'",
        "the Palace of Darius the Great",
        "the Leshan Giant Buddha",
        "the Island of Meroe",
        "Mesa Verde National Park",
        "Itchan Kala",
        "Bagan",
        "Rapa Nui National Park"
    };

    text += options[value % options.size()];

    sayWhatFrom(scramble(value));
}

void ourHero(int value) {
    string text = MyName;
    sayWhatTheyRescued(scramble(value));
}

void expressSurprise(int value) {
    if (value % 2 == 0) {
        string text = "when, suddenly,";
        ourHero(scramble(value));
    } else {
        string text = "when, without warning,";
        ourHero(scramble(value));
    }
}

void sayWhatTheyWereDoing(int value) {
    string text;
    switch (value % 10) {
    case 0:
        text = "was polishing the mirrors on the James Webb Space Telescope";
        break;
    case 1:
        text = "was reciting poetry";
        break;
    case 2:
        text = "was climbing the Vinson Massif";
        break;
    case 3:
        text = "was officiating at a wedding";
        break;
    case 4:
        text = "was searching for the deep truths of life";
        break;
    case 5:
        text = "was defending the indigent in federal court";
        break;
    case 6:
        text = "was recycling rare earth elements";
        break;
    case 7:
        text = "was unraveling the mysteries of the universe";
        break;
    case 8:
        text = "was mediating at peace talks";
        break;
    default:
        text = "was running a high-altitude marathon";
        break;
    }
    expressSurprise(scramble(value));
}

void introduceProtagonist(int value) {
    const Vector<string> options = {
        "Cherokee syllabary inventor Sequoyah",
        "actress and inventor Hedy Lamarr",
        "the polymath Ismail al-Jazari",
        "virologist Francoise Barre-Sinoussi",
        "banjo maestro Bela Fleck",
        "singer/songwriter Carole King",
        "abstract expressionist painter Lee Krasner",
        "Olympic athlete Steven Bradbury",
        "poet Wislawa Szymborska",
        "mathematician Srinivasa Ramanujan",
        "the writer Jorge Luis Borges"
    };

    string text = options[value % options.size()];
    sayWhatTheyWereDoing(scramble(value));
}

void beginStory(int value) {
    string text;
    if (value % 3 == 0) {
        text = "Once upon a time, ";
    } else if (value % 3 == 1) {
        text = "The other day, ";
    } else {
        text = "It once came to pass that ";
    }

    introduceProtagonist(scramble(value));
}
}

void tellStory() {
    if (MyName == "(Your Name Here)") {
        error("Please change the constant MyName defined in " __FILE__ " to your name.");
    }

    beginStory(hashCode(MyName));
}

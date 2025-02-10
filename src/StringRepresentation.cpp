// #include "StringRepresentation.h"

// using namespace std;

// namespace libforefire {

// // Static variables initialization
// FireDomain* domain = 0;
// size_t StringRepresentation::currentLevel = 0;
// ostringstream StringRepresentation::outputstr("");
// bool writedOnce = false;

// StringRepresentation::StringRepresentation(FireDomain* fdom) : Visitor() {
//     lastLevel = -1;
//     domain = fdom;
//     setTime(domain->getTime());
//     updateStep = SimulationParameters::GetInstance()->getDouble("outputsUpdate");
//     setUpdateTime(domain->getTime());
// }

// StringRepresentation::~StringRepresentation() {
// }

// void StringRepresentation::input(){
// }

// void StringRepresentation::update(){
//     setTime(getUpdateTime());
// }

// void StringRepresentation::timeAdvance(){
//     if (updateStep < EPSILONT) {
//         setUpdateTime(numeric_limits<double>::infinity());
//     } else {
//         setUpdateTime(getTime() + updateStep);
//     }
// }

// void StringRepresentation::output(){
//     if (writedOnce && (domain->getNumFF() == 0)) return;
//     writedOnce = true;

//     ostringstream oss;
//     oss << SimulationParameters::GetInstance()->getParameter("ffOutputsPattern") << "." << getTime();
//     ofstream outputfile(oss.str().c_str());
    
//     if (outputfile) {
//         outputfile << dumpStringRepresentation();
//     } else {
//         cout << "Could not open file " << oss.str() << " for writing domain file." << endl;
//     }
// }

// void StringRepresentation::visit(FireDomain* fd) {
//     outputstr.str("");
//     outputstr.clear();
//     outputstr << "{" << endl << "\t\"fronts\": [";  
//     lastLevel = 0;
//     firstFront = true;  // Flag to track first fire front
// }




// // void StringRepresentation::visit(FireFront* ff) {
// //     SimulationParameters *simParam = SimulationParameters::GetInstance();
    
// //     if (ff->getDomain()->getSimulationTime() >= ff->getTime()) {
// //         if (!firstFront) outputstr << ","; // Add a comma between multiple fire fronts
// //         firstFront = false; 

// //         double t = simParam->getInt("refTime") + ff->getDomain()->getSimulationTime();
// //         int d = simParam->getInt("refDay");
// //         int y = simParam->getInt("refYear");

// //         outputstr << endl << "\t\t{"; 
// //         outputstr << endl << "\t\t\t\"area\": \"" << fixed << (ff->getArea() / 10000) << "ha\","; 
// //         outputstr << endl << "\t\t\t\"date\": \"" << SimulationParameters::FormatISODate(t, y, d) << "\","; 
// //         outputstr << endl << "\t\t\t\"projection\": \"" << SimulationParameters::GetInstance()->getParameter("projection") << "\","; 
// //         outputstr << endl << "\t\t\t\"nodes\": [";

// //         lastLevel = 1;
// //         firstNode = true;  // Flag to track first node within a fire front
// //     }
// // }

// // void StringRepresentation::visit(FireFront* ff) {
// //     SimulationParameters *simParam = SimulationParameters::GetInstance();

// //     if (ff->getDomain()->getSimulationTime() >= ff->getTime()) {
// //         // Ensure previous fire front is properly closed
// //         if (lastLevel >= 2) outputstr << endl << "\t\t\t]"; // Close previous front's nodes array
// //         if (lastLevel >= 1) outputstr << endl << "\t\t}";   // Close previous front's object

// //         if (!firstFront) outputstr << ","; // Add a comma between multiple fire fronts
// //         firstFront = false;

// //         double t = simParam->getInt("refTime") + ff->getDomain()->getSimulationTime();
// //         int d = simParam->getInt("refDay");
// //         int y = simParam->getInt("refYear");

// //         outputstr << endl << "\t\t{";
// //         outputstr << endl << "\t\t\t\"area\": \"" << fixed << (ff->getArea() / 10000) << "ha\",";
// //         outputstr << endl << "\t\t\t\"date\": \"" << SimulationParameters::FormatISODate(t, y, d) << "\",";
// //         outputstr << endl << "\t\t\t\"projection\": \"" << simParam->getParameter("projection") << "\",";
// //         outputstr << endl << "\t\t\t\"nodes\": [";

// //         lastLevel = 1;
// //         firstNode = true;
// //     }
// // }

// void StringRepresentation::visit(FireFront* ff) {
//     SimulationParameters *simParam = SimulationParameters::GetInstance();
    
//     if (ff->getDomain()->getSimulationTime() >= ff->getTime()) {
//         if (!firstFront) outputstr << ","; // Add a comma between multiple fire fronts
//         firstFront = false; 

//         double t = simParam->getInt("refTime") + ff->getDomain()->getSimulationTime();
//         int d = simParam->getInt("refDay");
//         int y = simParam->getInt("refYear");

//         outputstr << endl << "\t\t{"; 
//         outputstr << endl << "\t\t\t\"area\": \"" << fixed << (ff->getArea() / 10000) << "ha\","; 
//         outputstr << endl << "\t\t\t\"date\": \"" << SimulationParameters::FormatISODate(t, y, d) << "\","; 
//         outputstr << endl << "\t\t\t\"projection\": \"" << SimulationParameters::GetInstance()->getParameter("projection") << "\","; 
//         outputstr << endl << "\t\t\t\"nodes\": [";

//         lastLevel = 1;
//         firstNode = true;  // Flag to track first node within a fire front
//     }
// }

// // void StringRepresentation::visit(FireNode* fn) {
// //     if (fn->getFront()->getDomain()->getSimulationTime() >= fn->getFront()->getTime()) {
// //         if (!firstNode) outputstr << ","; // Add a comma between multiple nodes
// //         firstNode = false;

// //         outputstr.precision(3);
// //         int fuel = fn->getFront()->getDomain()->getDataBroker()->getLayer("fuel")->getValueAt(fn->getLoc(), fn->getTime());

// //         outputstr << endl << "\t\t\t\t{"; 
// //         outputstr << "\"id\": " << fn->getID() << ", ";
// //         outputstr << "\"location\": [" << fn->getX() << ", " << fn->getY() << "], ";
// //         outputstr << "\"speed\": " << fn->getSpeed() << ", ";
// //         outputstr << "\"arrival_time\": " << fn->getTime() << ", ";
// //         outputstr << "\"fuel\": " << fuel;
// //         outputstr << "}";

// //         lastLevel = 2;
// //     }
// // }

// void StringRepresentation::visit(FireNode* fn) {
//     if (fn->getFront()->getDomain()->getSimulationTime() >= fn->getFront()->getTime()) {
//         if (!firstNode) outputstr << ","; // Add a comma between multiple nodes
//         firstNode = false;

//         outputstr.precision(3);
//         int fuel = fn->getFront()->getDomain()->getDataBroker()->getLayer("fuel")->getValueAt(fn->getLoc(), fn->getTime());

//         outputstr << endl << "\t\t\t\t{"; 
//         outputstr << "\"id\": " << fn->getID() << ", ";
//         outputstr << "\"location\": [" << fn->getX() << ", " << fn->getY() << "], ";
//         outputstr << "\"speed\": " << fn->getSpeed() << ", ";
//         outputstr << "\"arrival_time\": " << fn->getTime() << ", ";
//         outputstr << "\"fuel\": " << fuel;
//         outputstr << "}";

//         lastLevel = 2;
//     }
// }

// // string StringRepresentation::dumpStringRepresentation() {
// //     currentLevel = 0;
// //     lastLevel = -1;

// //     outputstr.str("");
// //     outputstr.clear();

// //     if (domain != nullptr) domain->accept(this);

// //     // Ensure proper closure of JSON structures
// //     if (lastLevel >= 2) outputstr << endl << "\t\t\t]"; // Close nodes array
// //     if (lastLevel >= 1) outputstr << endl << "\t\t}";   // Close fire front object

// //     outputstr << endl << "\t]" << endl;  // Close "fronts" array
// //     outputstr << "}";  // Close root object

// //     return outputstr.str();
// // }

// // string StringRepresentation::dumpStringRepresentation() {
// //     currentLevel = 0;
// //     lastLevel = -1;

// //     outputstr.str("");
// //     outputstr.clear();

// //     if (domain != nullptr) domain->accept(this);

// //     // Ensure all open fire fronts are closed
// //     if (lastLevel >= 2) outputstr << endl << "\t\t\t]"; // Close last nodes array
// //     if (lastLevel >= 1) outputstr << endl << "\t\t}";   // Close last fire front object

// //     outputstr << endl << "\t]" << endl;  // Close "fronts" array
// //     outputstr << "}";  // Close root object

// //     return outputstr.str();
// // }

// string StringRepresentation::dumpStringRepresentation() {
//     currentLevel = 0;
//     lastLevel = -1;

//     outputstr.str("");
//     outputstr.clear();

//     if (domain != nullptr) {
//         domain->accept(this);
//     }

//     // Ensure proper closure of JSON structures
//     if (lastLevel >= 2) outputstr << endl << "\t\t\t]"; // Close nodes array
//     if (lastLevel >= 1) outputstr << endl << "\t\t}";   // Close fire front object

//     outputstr << endl << "\t]" << endl;  // Close "fronts" array
//     outputstr << "}";  // Close root object

//     return outputstr.str();
// }

// void StringRepresentation::increaseLevel(){
//     currentLevel++;
// }

// void StringRepresentation::decreaseLevel(){
//     currentLevel--;
// }

// size_t StringRepresentation::getLevel(){
//     return currentLevel;
// }

// string StringRepresentation::toString(){
//     ostringstream oss;
//     oss << "string representation";
//     return oss.str();
// }

// void StringRepresentation::setOutPattern(string s){
//     outPattern = s;
// }

// } // namespace libforefire


#include "StringRepresentation.h"

using namespace std;


namespace libforefire {

// Static variables initialization
FireDomain* domain = 0;
size_t StringRepresentation::currentLevel = 0;
ostringstream StringRepresentation::outputstr("");
bool writedOnce = false;

StringRepresentation::StringRepresentation(FireDomain* fdom) : Visitor() {
    lastLevel = -1;
    domain = fdom;
    setTime(domain->getTime());
    updateStep = SimulationParameters::GetInstance()->getDouble("outputsUpdate");
    setUpdateTime(domain->getTime());
}

StringRepresentation::~StringRepresentation() {
}

void StringRepresentation::input(){
}

void StringRepresentation::update(){
    setTime(getUpdateTime());
}

void StringRepresentation::timeAdvance(){
    if (updateStep < EPSILONT) {
        setUpdateTime(numeric_limits<double>::infinity());
    } else {
        setUpdateTime(getTime() + updateStep);
    }
}

void StringRepresentation::output(){
    if (writedOnce && (domain->getNumFF() == 0)) return;
    writedOnce = true;

    ostringstream oss;
    oss << SimulationParameters::GetInstance()->getParameter("ffOutputsPattern") << "." << getTime();
    ofstream outputfile(oss.str().c_str());
    
    if (outputfile) {
        outputfile << dumpStringRepresentation();
    } else {
        cout << "Could not open file " << oss.str() << " for writing domain file." << endl;
    }
}

void StringRepresentation::visit(FireDomain* fd) {
    // Reset output for a new domain visit
    outputstr.str("");
    outputstr.clear();
    outputstr << "{" << endl << "\t\"fronts\": [";  
    lastLevel = 0;
    firstFront = true;  // Flag to track whether we are processing the first fire front
}



void StringRepresentation::visit(FireFront* ff) {
    SimulationParameters* simParam = SimulationParameters::GetInstance();

    if (ff->getDomain()->getSimulationTime() >= ff->getTime()) {
        if (!firstFront) outputstr << ","; // Add a comma between multiple fire fronts
        firstFront = false;

        double t = simParam->getInt("refTime") + ff->getDomain()->getSimulationTime();
        int d = simParam->getInt("refDay");
        int y = simParam->getInt("refYear");

        outputstr << endl << "\t\t{";
        outputstr << endl << "\t\t\t\"area\": \"" << fixed << (ff->getArea() / 10000) << "ha\",";
        outputstr << endl << "\t\t\t\"date\": \"" << SimulationParameters::FormatISODate(t, y, d) << "\",";
        outputstr << endl << "\t\t\t\"projection\": \"" << simParam->getParameter("projection") << "\",";
        outputstr << endl << "\t\t\t\"nodes\": [";

        lastLevel = 1;
        firstNode = true;
    }
}


void StringRepresentation::visit(FireNode* fn) {
    if (fn->getFront()->getDomain()->getSimulationTime() >= fn->getFront()->getTime()) {
        if (!firstNode) outputstr << ","; // Add a comma between nodes
        firstNode = false;

        outputstr.precision(3);
        int fuel = fn->getFront()->getDomain()->getDataBroker()->getLayer("fuel")->getValueAt(fn->getLoc(), fn->getTime());

        outputstr << endl << "\t\t\t\t{"; 
        outputstr << "\"id\": " << fn->getID() << ", ";
        outputstr << "\"location\": [" << fn->getX() << ", " << fn->getY() << "], ";
        outputstr << "\"speed\": " << fn->getSpeed() << ", ";
        outputstr << "\"arrival_time\": " << fn->getTime() << ", ";
        outputstr << "\"fuel\": " << fuel;
        outputstr << "}";
    }
}

string StringRepresentation::dumpStringRepresentation() {
    currentLevel = 0;
    lastLevel = -1;

    outputstr.str("");
    outputstr.clear();

    if (domain != nullptr) {
        domain->accept(this);
    }

    // Ensure proper closure of JSON structures
    if (lastLevel >= 1) outputstr << endl << "\t\t\t]"; // Ensure nodes array is closed
    if (lastLevel >= 0) outputstr << endl << "\t\t}";   // Ensure fire front object is closed

    outputstr << endl << "\t]" << endl;  // Ensure "fronts" array is closed
    outputstr << "}";  // Close root object

    return outputstr.str();
}


void StringRepresentation::increaseLevel(){
    currentLevel++;
}

void StringRepresentation::decreaseLevel(){
    currentLevel--;
}

size_t StringRepresentation::getLevel(){
    return currentLevel;
}

string StringRepresentation::toString(){
    ostringstream oss;
    oss << "string representation";
    return oss.str();
}

void StringRepresentation::setOutPattern(string s){
   outPattern = s;
}

} // namespace libforefire
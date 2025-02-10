// // // /*

// // // Copyright (C) 2012 ForeFire Team, SPE, Universit� de Corse.

// // // This program is free software; you can redistribute it and/or
// // // modify it under the terms of the GNU Lesser General Public
// // // License as published by the Free Software Foundation; either
// // // version 2.1 of the License, or (at your option) any later version.

// // // This program is distributed in the hope that it will be useful,
// // // but WITHOUT ANY WARRANTY; without even the implied warranty of
// // // MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU
// // // Lesser General Public License for more details.

// // // You should have received a copy of the GNU Lesser General Public
// // // License along with this program; if not, write to the Free Software
// // // Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301 US

// // // */

// // // #include "StringRepresentation.h"
// // // #include <iostream>
// // // #include <typeinfo>
// // // #include <fstream>
// // // #include <vector>

// // // using namespace std;

// // // namespace libforefire {

// // // // static variables initialization

// // // size_t StringRepresentation::currentLevel = 0;
// // // ostringstream StringRepresentation::outputstr("");
// // // bool writedOnce = false;
// // // string outPattern;
// // // FireDomain* domain = 0;
// // // StringRepresentation::StringRepresentation(FireDomain* fdom) : Visitor() {
// // //     lastLevel = -1;
// // // 	domain = fdom;
 
// // //     outPattern = SimulationParameters::GetInstance()->getParameter("ffOutputsPattern");
// // // 	setTime(domain->getTime());
// // // 	updateStep = SimulationParameters::GetInstance()->getDouble("outputsUpdate");
// // // 	setUpdateTime(domain->getTime());
// // // }

// // // StringRepresentation::~StringRepresentation() { 
// // // }

// // // void StringRepresentation::input(){
// // // }

// // // void StringRepresentation::setOutPattern(string s){
// // //     outPattern = s;
// // // }

// // // void StringRepresentation::update(){
// // // 	setTime(getUpdateTime());
// // // }

// // // void StringRepresentation::timeAdvance(){
// // // 	if ( updateStep < EPSILONT ){
// // // 		setUpdateTime(numeric_limits<double>::infinity());
// // // 	} else {
// // // 		setUpdateTime(getTime()+updateStep);
// // // 	}
// // // }

// // // void StringRepresentation::output(){

// // // 	if (writedOnce && (domain->getNumFF()==0) ) return;

// // // 	writedOnce= true;

// // // 	ostringstream oss;

// // // 	oss<<outPattern<<"."<<getTime();
// // // 	ofstream outputfile(oss.str().c_str());
// // // 	if ( outputfile ) {
// // // 		outputfile<<dumpStringRepresentation();
// // // 	} else {
// // // 		cout<<"could not open file "<<oss.str()<<" for writing domain file "<<endl;
// // // 	}
// // // }

// // // void StringRepresentation::visit(FireDomain* fd) {
// // //     outputstr << '{' << endl << '\t' << "\"fronts\": [";
// // //     lastLevel = 0;
// // // }

// // // void StringRepresentation::visit(FireFront* ff) {
// // //     SimulationParameters *simParam = SimulationParameters::GetInstance();
    
// // //     if (ff->getDomain()->getSimulationTime() >= ff->getTime())
// // //     {
// // //         if (lastLevel >= 2)
// // //             outputstr << '"';
// // //         if (lastLevel >= 1)
// // //             outputstr << endl << '\t' << "},";
        
// // //         double t = simParam->getInt("refTime") + ff->getDomain()->getSimulationTime();
// // //         int d = simParam->getInt("refDay");
// // //         int y = simParam->getInt("refYear");

// // //         outputstr.precision(3);
// // //         outputstr << endl << '\t' << '{';
// // //         outputstr << endl << "\t\t" << "\"area\":\"";
// // //         outputstr << fixed << (ff->getArea() / 10000) << "ha\",";
// // //         outputstr << endl << "\t\t" << "\"date\":\"";
// // //         outputstr << SimulationParameters::FormatISODate(t, y, d) << "\",";
// // //         outputstr << endl << "\t\t" << "\"projection\":\"";
// // //         outputstr << SimulationParameters::GetInstance()->getParameter("projection") << "\",";
// // //         outputstr << endl << "\t\t" << "\"coordinates\":\"";
// // //         lastLevel = 1;
// // //     }
// // // }

// // // void StringRepresentation::visit(FireNode* fn) {
// // //     if (fn->getFront()->getDomain()->getSimulationTime() >= fn->getFront()->getTime())
// // //         {
// // //             if (lastLevel == 2)
// // //                 outputstr << ' ';

// // //             outputstr.precision(3);
// // //             int fuel;
// // //             fuel = fn->getFront()->getDomain()->getDataBroker()->getLayer("fuel")->getValueAt(fn->getLoc(),fn->getTime());

// // //             outputstr << "\t\t\t\t\"" << fn->getID() << "\": {";
// // //             outputstr << "\"location\": [" << fn->getX() << ',' << fn->getY() << "], \"speed\": " << fn->getSpeed() << ", \"arrival_time\": " << fn->getTime() << ", \"fuel\": " << fuel << "}," << endl;
// // //             lastLevel = 2;
// // //         }
// // //         return;
// // // }

// // // string StringRepresentation::dumpStringRepresentation() {
// // // 	currentLevel = 0;
// // //     lastLevel = -1;
    
// // // 	outputstr.str("");
// // // 	if (domain != 0) domain->accept(this);
    
// // //     outputstr.seekp(-2, std::ios_base::end);
// // //     outputstr << endl;
// // //     outputstr << "\t\t\t}" << endl;
// // //     outputstr << "\t\t}" << endl;
// // //     outputstr << "\t]" << endl;
// // //     outputstr << "}" << endl;
    
// // // 	return outputstr.str();
// // // }

// // // void StringRepresentation::increaseLevel(){
// // // 	currentLevel++;
// // // }

// // // void StringRepresentation::decreaseLevel(){
// // // 	currentLevel--;
// // // }

// // // size_t StringRepresentation::getLevel(){
// // // 	return currentLevel;
// // // }

// // // string StringRepresentation::toString(){
// // // 	ostringstream oss;
// // // 	oss<<"string representation";
// // // 	return oss.str();
// // // }

// // // }


// // /*

// // Copyright (C) 2012 ForeFire Team, SPE, Université de Corse.

// // This program is free software; you can redistribute it and/or
// // modify it under the terms of the GNU Lesser General Public
// // License as published by the Free Software Foundation; either
// // version 2.1 of the License, or (at your option) any later version.

// // This program is distributed in the hope that it will be useful,
// // but WITHOUT ANY WARRANTY; without even the implied warranty of
// // MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU
// // Lesser General Public License for more details.

// // You should have received a copy of the GNU Lesser General Public
// // License along with this program; if not, write to the Free Software
// // Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301 US

// // */

// // #include "StringRepresentation.h"
// // #include <iostream>
// // #include <typeinfo>
// // #include <fstream>
// // #include <vector>

// // using namespace std;

// // namespace libforefire {

// // // static variables initialization
// // size_t StringRepresentation::currentLevel = 0;
// // ostringstream StringRepresentation::outputstr("");
// // bool writedOnce = false;
// // string outPattern;
// // FireDomain* domain = nullptr;

// // StringRepresentation::StringRepresentation(FireDomain* fdom) : Visitor() {
// //     lastLevel = -1;
// //     domain = fdom;
 
// //     outPattern = SimulationParameters::GetInstance()->getParameter("ffOutputsPattern");
// //     setTime(domain->getTime());
// //     updateStep = SimulationParameters::GetInstance()->getDouble("outputsUpdate");
// //     setUpdateTime(domain->getTime());
// // }

// // StringRepresentation::~StringRepresentation() { 
// // }

// // void StringRepresentation::input() {
// // }

// // void StringRepresentation::setOutPattern(string s) {
// //     outPattern = s;
// // }

// // void StringRepresentation::update() {
// //     setTime(getUpdateTime());
// // }

// // void StringRepresentation::timeAdvance() {
// //     if (updateStep < EPSILONT) {
// //         setUpdateTime(numeric_limits<double>::infinity());
// //     } else {
// //         setUpdateTime(getTime() + updateStep);
// //     }
// // }

// // void StringRepresentation::output() {
// //     if (writedOnce && (domain->getNumFF() == 0)) return;

// //     writedOnce = true;

// //     ostringstream oss;
// //     oss << outPattern << "." << getTime();
// //     ofstream outputfile(oss.str().c_str());
// //     if (outputfile) {
// //         outputfile << dumpStringRepresentation();
// //     } else {
// //         cout << "Could not open file " << oss.str() << " for writing domain file" << endl;
// //     }
// // }

// // void StringRepresentation::visit(FireDomain* fd) {
// //     outputstr.str("");
// //     outputstr.clear();
// //     outputstr << "{" << endl << "\t\"fronts\": [";  
// //     lastLevel = 0;
// // }

// // void StringRepresentation::visit(FireFront* ff) {
// //     SimulationParameters *simParam = SimulationParameters::GetInstance();
    
// //     if (ff->getDomain()->getSimulationTime() >= ff->getTime()) {
// //         if (lastLevel >= 1) outputstr << "\n\t\t}"; // Close previous fire front
// //         if (lastLevel >= 2) outputstr << "\n\t\t]"; // Close coordinates array

// //         double t = simParam->getInt("refTime") + ff->getDomain()->getSimulationTime();
// //         int d = simParam->getInt("refDay");
// //         int y = simParam->getInt("refYear");

// //         outputstr << (lastLevel >= 1 ? "," : "") << endl << "\t\t{"; 
// //         outputstr << endl << "\t\t\t\"area\": \"" << fixed << (ff->getArea() / 10000) << "ha\","; 
// //         outputstr << endl << "\t\t\t\"date\": \"" << SimulationParameters::FormatISODate(t, y, d) << "\","; 
// //         outputstr << endl << "\t\t\t\"projection\": \"" << SimulationParameters::GetInstance()->getParameter("projection") << "\","; 
// //         outputstr << endl << "\t\t\t\"coordinates\": ["; 
        
// //         lastLevel = 1;
// //     }
// // }

// // void StringRepresentation::visit(FireNode* fn) {
// //     if (fn->getFront()->getDomain()->getSimulationTime() >= fn->getFront()->getTime()) {
// //         if (lastLevel == 2) outputstr << ","; // Add comma between nodes

// //         outputstr.precision(3);
// //         int fuel = fn->getFront()->getDomain()->getDataBroker()->getLayer("fuel")->getValueAt(fn->getLoc(), fn->getTime());
// //         // int fuel = fn->getFront()->getDomain()->getDataBroker()->getLayer("fuel")->getPos(fn->getLoc(), fn->getTime());
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

// // string StringRepresentation::dumpStringRepresentation() {
// //     currentLevel = 0;
// //     lastLevel = -1;

// //     outputstr.str("");
// //     outputstr.clear();

// //     if (domain != nullptr) domain->accept(this);

// //     if (lastLevel >= 2) outputstr << endl << "\t\t\t]"; // Close coordinates array
// //     if (lastLevel >= 1) outputstr << endl << "\t\t}";   // Close fire front object

// //     outputstr << endl << "\t]" << endl;  // Close "fronts" array
// //     outputstr << "}";  // Close root object

// //     return outputstr.str();
// // }

// // void StringRepresentation::increaseLevel() {
// //     currentLevel++;
// // }

// // void StringRepresentation::decreaseLevel() {
// //     currentLevel--;
// // }

// // size_t StringRepresentation::getLevel() {
// //     return currentLevel;
// // }

// // string StringRepresentation::toString() {
// //     return "string representation";
// // }

// // }

// #include "StringRepresentation.h"

// using namespace std;

// namespace libforefire {

// // Static variables initialization
// FireDomain* StringRepresentation::domain = 0;
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

// void StringRepresentation::input() {
// }

// void StringRepresentation::update() {
//     setTime(getUpdateTime());
// }

// void StringRepresentation::timeAdvance() {
//     if (updateStep < EPSILONT) {
//         setUpdateTime(numeric_limits<double>::infinity());
//     } else {
//         setUpdateTime(getTime() + updateStep);
//     }
// }

// void StringRepresentation::output() {
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
//     outputstr << "{\n\t\"fronts\": [";  
//     lastLevel = 0;
// }

// void StringRepresentation::visit(FireFront* ff) {
//     SimulationParameters *simParam = SimulationParameters::GetInstance();
    
//     if (ff->getDomain()->getSimulationTime() >= ff->getTime()) {
//         if (lastLevel >= 1) outputstr << "\n\t\t}"; // Close previous fire front before adding a comma

//         if (!firstFront) outputstr << ","; // Add comma only if it's not the first front
//         firstFront = false;

//         double t = simParam->getInt("refTime") + ff->getDomain()->getSimulationTime();
//         int d = simParam->getInt("refDay");
//         int y = simParam->getInt("refYear");

//         outputstr << "\n\t\t{"; 
//         outputstr << "\n\t\t\t\"area\": \"" << fixed << (ff->getArea() / 10000) << "ha\","; 
//         outputstr << "\n\t\t\t\"date\": \"" << SimulationParameters::FormatISODate(t, y, d) << "\","; 
//         outputstr << "\n\t\t\t\"projection\": \"" << SimulationParameters::GetInstance()->getParameter("projection") << "\","; 
//         outputstr << "\n\t\t\t\"nodes\": ["; 
        
//         firstNode = true; // Reset node tracking for this front
//         lastLevel = 1;
//     }
// }


// void StringRepresentation::visit(FireNode* fn) {
//     if (fn->getFront()->getDomain()->getSimulationTime() >= fn->getFront()->getTime()) {
//         if (lastLevel == 2) outputstr << ","; // Add comma between nodes

//         outputstr.precision(3);
//         int fuel = fn->getFront()->getDomain()->getDataBroker()->getLayer("fuel")->getValueAt(fn->getLoc(), fn->getTime());

//         outputstr << "\n\t\t\t\t{"; 
//         outputstr << "\"id\": " << fn->getID() << ", ";
//         outputstr << "\"location\": [" << fn->getX() << ", " << fn->getY() << "], ";
//         outputstr << "\"speed\": " << fn->getSpeed() << ", ";
//         outputstr << "\"arrival_time\": " << fn->getTime() << ", ";
//         outputstr << "\"fuel\": " << fuel;
//         outputstr << "}";

//         lastLevel = 2;
//     }
// }

// string StringRepresentation::dumpStringRepresentation() {
//     currentLevel = 0;
//     lastLevel = -1;

//     outputstr.str("");
//     outputstr.clear();

//     if (domain != nullptr) domain->accept(this);

//     if (lastLevel >= 2) outputstr << "\n\t\t\t]"; // Close nodes array
//     if (lastLevel >= 1) outputstr << "\n\t\t}";   // Close fire front object

//     outputstr << "\n\t]" << "\n}";  // Close "fronts" array and root object

//     return outputstr.str();
// }

// void StringRepresentation::increaseLevel() {
//     currentLevel++;
// }

// void StringRepresentation::decreaseLevel() {
//     currentLevel--;
// }

// size_t StringRepresentation::getLevel() {
//     return currentLevel;
// }

// string StringRepresentation::toString() {
//     ostringstream oss;
//     oss << "string representation";
//     return oss.str();
// }

// }

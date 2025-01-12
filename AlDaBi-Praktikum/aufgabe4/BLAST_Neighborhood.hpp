#pragma once 

#include <string>
#include <vector>
//#include <omp.h> // not needed here, but in .cpp


#include "a4_util.h"

// ... more includes here...


/**
   Neighborhood Result data for a single infix
   e.g. infix: "AHI" 
         neighbors: (AHI, 16); (AHL, 14); (AHV, 15)
    Remember: members in structs are public by default.
              So you can initialize and use them like this (for example; other approaches possible):
      std::vector< std::pair <std::string, int> > my_vec;
      my_vec.push_back(make_pair("AGT", 23));
      my_vec.emplace_back("ATT", 21);  // even better (faster)
      NHResult r{"AAA", my_vec};
      
      NHResult other_r;
      other_r.infix = "BLA";
      other_r.neighbors = my_vec;
 */
struct NHResult
{
  std::string infix;
  std::vector< std::pair <std::string, int> > neighbors;
};


class BLAST_Neighborhood
{
  // do NOT change the public interface
  public:
    /**
     Berechnet die BLAST Nachbarschaft fuer eine Query.
    
     @param query           Die Eingabesequenz, welche in Infixe der Länge @p word_size zerlegt wird
     @param matrix          Die Scoring-Matrix fuer das Berechnen der Nachbarschaft
     @param word_size       Die zu verwendende Wortgroesse
     @param score_threshold Der minimale Score den ein Wort haben muss um zur Nachbarschaft zugehoeren
     @param threads         Die Anzahl der Threads die verwendet werden sollen
     @return Die Nachbarschaften der Query-Infixe, sortiert nach Position der Infixe in Query (d.h. 1. Infix, 2. Infix, ...).
	         Die Nachbarschaft jedes Infixes ist alphabetisch sortiert.
     @throw Wirft eine Exception, wenn @p threads != 1 ist (ohne Zusatzaufgabe), bzw <= 0 (mit Zusatzaufgabe)
    */
    std::vector<NHResult> generateNeighborhood(const std::string& query,
                                               const ScoreMatrix& matrix,
                                               const int word_size,
                                               const int score_threshold,
                                               const int threads);
                              

  
  private:
  // your private member _functions_ go here <> (if needed)
  void findNeighborsRecursive(const int pos, const int word_size,int score,int score_threshold,NHResult& substring,std::string word,const std::vector<char> alphabet,const ScoreMatrix& matrix, int threads);
  // hint: private member _variables_ are probably not required 
  
};

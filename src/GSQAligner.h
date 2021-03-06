/*
 * GSQAligner.h
 *
 *  Created on: Oct 15, 2011
 *     Authors: Hsien-chao Chou (first version); Thomas McCarthy and Volker Brendel (modifications)
 */

#ifndef GSQALIGNER_H_
#define GSQALIGNER_H_

#include "SplicedAligner.h"
#include <boost/unordered_map.hpp>

class GSQAligner: public SplicedAligner {
public:
	GSQAligner(int, string);
	virtual ~GSQAligner();
	bool is_available();
	string_map get_aligned_contigs(const double& min_score, const double& min_coverage, const unsigned int& min_contig_lgth, const string& all_contig_file, const string& hit_contig_file, const string& alignment_file, const int round, tuple_map& best_hits);
	void get_hit_contigs(const double& min_score, const double& min_coverage, const unsigned int& min_contig_lgth, const string& final_contigs_file, const string& hit_contig_file, const string& alignment_file, tuple_map& best_hits);
	int get_longest_match(int round, int k, const double& min_score, const unsigned int& query_contig_min, const string& alignment_file, tuple_map& best_hits);
	void do_spliced_alignment(const string& genomic_file, const string& query_type, const string& probe_file, const string& species, const Params& params, const string& output_file);
	string get_program_name();
	void clean_files(const string&);
private:
	boost::unordered_map<string, string> species_names;
};

#endif /* GSQALIGNER_H_ */

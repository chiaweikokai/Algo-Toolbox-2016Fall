#include <algorithm>
#include <iostream>
#include <climits>
#include <vector>

struct Segment
{
    int start, end;

    Segment() :
        start(0),
        end(0)
        {

        }

    Segment(int _start, int _end) :
        start(_start),
        end(_end)
        {

        }
};


bool is_num_contained(Segment seg, int num) {
    if (num < seg.start || num > seg.end) return false;
    else return true;
}


std::vector<int> get_optimal_points(std::vector<Segment> segments) {
    std::vector<int> optimal_points;
    optimal_points.clear();
    std::vector<int> rest_points;
    rest_points.clear();   

    while (segments.size() > 1) {
        for (size_t i = 0; i < segments.size(); ++i) {
            rest_points.push_back(segments[i].start);
            rest_points.push_back(segments[i].end);
        }
        int max_num = *std::max_element(rest_points.begin(), rest_points.end());
        int min_num = *std::min_element(rest_points.begin(), rest_points.end());
        int max_count = 0;
        int max_count_num = 0;
        for (int num = min_num; num <= max_num; num++) {
            int count_this_num = 0;
            for (size_t i = 0; i < segments.size(); i++) { 
                if ( is_num_contained(segments[i], num) ) count_this_num++;
            }
            if (count_this_num > max_count) {
                max_count = count_this_num;
                max_count_num = num;
            }
        }
        for (size_t i = 0; i < segments.size(); i++) {
            if ( is_num_contained(segments[i], max_count_num) )
            {
                segments.erase(segments.begin() + i);
            }
        }
        // std::cout << segments.size() << std::endl;
        optimal_points.push_back(max_count_num);
    }
/*
    for (size_t i = 0; i < segments.size(); ++i) {
        points.push_back(segments[i].start);
        points.push_back(segments[i].end);
    }
*/
    return optimal_points;
}

int main() {
    int n;
    std::cin >> n;
    std::vector<Segment> segments(n);
    // Segment s1(1, 3);
    // Segment s2(2, 5);
    // Segment s3(3, 6);
    // segments.push_back(s1);
    // segments.push_back(s2);
    // segments.push_back(s3);
    
    for (size_t i = 0; i < segments.size(); ++i) {
        std::cin >> segments[i].start >> segments[i].end;
    }
    
    std::vector<int> points = get_optimal_points(segments);
    std::cout << points.size() << std::endl;
    for (size_t i = 0; i < points.size(); ++i) {
        std::cout << points[i] << " ";
    }
    std::cout << std::endl;
    return 0;
}




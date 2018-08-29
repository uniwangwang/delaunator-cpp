#pragma once
#include <vector>
#include <exception>
#include <deque>
#include <memory>

struct DelaunatorPoint {
    long int i;
    double x;
    double y;
    long int t;
    long int prev;
    long int next;
    bool removed;
};

class Delaunator{
    public:
        Delaunator(const std::vector<double> &in_coords);
        std::vector<unsigned long int> triangles;
        std::vector<long int> halfedges;
        std::vector<double> coords;
    private:
        double m_center_x;
        double m_center_y;
        long int m_hash_size;
        std::vector<int> m_hash;
        std::vector<DelaunatorPoint> m_hull;
        long int insert_node(long int i);
        long int insert_node(long int i, long int prev);
        long int hash_key(double x, double y);
        void hash_edge(long int e);
        long int add_triangle(
            long int i0, long int i1, long int i2,
            long int a, long int b, long int c
        );
        void link(long int a, long int b);
        long int legalize(long int a);
        long int remove_node(long int node);
};

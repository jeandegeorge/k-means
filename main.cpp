#include <iostream>
#include<tuple>
#include<vector>
#include<cmath>
#include<map>
#include <fstream>
#include <string>
#include <sstream>
#include <fstream>
#include <map>

std::vector<std::vector<float>> computeNewCentroid(std::vector<std::vector<float>> dataPoints){
    return dataPoints;
}



void getMin(std::vector<float> dataPoint, int centroid);

float computeEuclideanDistance(std::vector<float> dataPoint1, std::vector<float> dataPoint2){
    double sum=0;
    for (int i=0;i<dataPoint1.size();i++) {
        float &a = dataPoint1[i];
        float &b = dataPoint2[i];
        float x = a-b;
        sum += std::pow(x, 2);
    }
    sum = std::sqrt(sum);
    return (float)sum;
}

float assignLabel(std::vector<float> dataPoint, std::map<int, std::vector<float>> centroids){
    std::vector<float> distances;
    for (auto centroid: centroids) {
        //float distance = computeEuclideanDistance(dataPoint, centroid);
        //distances.push_back(distance);
    }
    std::sort(distances.begin(),distances.end());
    return distances[0];
}

float randFloatRange(float a, float b)
{
    return ((b - a) * ((float)rand() / RAND_MAX)) + a;
}

std::vector<std::tuple<int, std::vector<float>>> generateCentroids(int k)
{
    std::vector<std::tuple<int, std::vector<float>>> centroids;
    for(int i=0;i<k;i++){
        std::vector<float> vec = {randFloatRange(0, 10), randFloatRange(0, 10)};
        std::tuple<int, std::vector<float>> tup(i, vec);
        centroids.push_back(tup);
    }
    return centroids;
}




int main() {

    std::ifstream file;

    std::string label;

    std::string temp, temp2;

    std::stringstream ss(temp);

    std::vector<float> dataPoint;

    std::vector<std::tuple<int, std::vector<float>>> dataPoints;

    int i=0;

    file.open("data.txt");

    while (getline(file, temp, ' ')) {

        i++;

        dataPoint.push_back(std::stof(temp));
        //std::cout << "(" << temp << "," ;

        getline(file, temp2);
        dataPoint.push_back(std::stof(temp2));
        //std::cout << " " << temp2 << ")" ;

        //std::cout << std::endl;

        for (auto j: dataPoint){
            //std::cout << j << " ";
            //std::cout << std::endl;
        }

        std::tuple<int, std::vector<float>> tempTuple (i, dataPoint);
        dataPoints.push_back(tempTuple);

        //std::cout << std::get<1>(dataPoints[0])[0]  << ' ' << std::get<1>(dataPoints[0])[1] << std::endl;

        dataPoint = {};
    }

    file.close();
    //std::vector<std::vector<float>> centroids;


    // Tests

    for (auto tup: dataPoints){

        std::cout << std::get<1>(tup)[0]  << ' ' << std::get<1>(tup)[1] << std::endl;

    }

    std::cout<<computeEuclideanDistance(std::get<1>(dataPoints[0]), std::get<1>(dataPoints[1]))<<std::endl;

    std::vector<std::tuple<int, std::vector<float>>> centroids = generateCentroids(3);
    std::vector<std::tuple<int, int, float>> distances;

    for(int i=0; i<dataPoints.size(); i++){
        for(int j=0; j<3; j++){
            float tempDist = computeEuclideanDistance(std::get<1>(dataPoints[0]), std::get<1>(centroids[j]));
            std::cout<<tempDist<<std::endl;
            std::tuple<int, int, float> tempTup(i, j, tempDist);
            distances.push_back(tempTup);
        }
        distances[2];
    }

    return 0;
}

// return ID of nearest center (uses euclidean distance)
int getIDNearestCenter(Point point)
{
    double sum = 0.0, min_dist;
    int id_cluster_center = 0;

    for(int i = 0; i < total_values; i++)
    {
        sum += pow(clusters[0].getCentralValue(i) -
                   point.getValue(i), 2.0);
    }

    min_dist = sqrt(sum);

    for(int i = 1; i < K; i++)
    {
        double dist;
        sum = 0.0;

        for(int j = 0; j < total_values; j++)
        {
            sum += pow(clusters[i].getCentralValue(j) -
                       point.getValue(j), 2.0);
        }

        dist = sqrt(sum);

        if(dist < min_dist)
        {
            min_dist = dist;
            id_cluster_center = i;
        }
    }

    return id_cluster_center;
}
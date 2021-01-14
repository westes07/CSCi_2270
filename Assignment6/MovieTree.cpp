#include "MovieTree.hpp"
#include <iostream>
#include <string>
#include<fstream>
#include <sstream>

using namespace std;

// MovieNode: node struct that will be stored in the MovieTree BST
MovieNode* getMovieNode(int rank, string t, int y, float r) {
    MovieNode* nn = new MovieNode;
    nn->title = t;
    nn->ranking = rank;
    nn->year = y;
    nn->rating = r;
    return nn;
}

MovieTree::MovieTree() {
  //write your code
  root = NULL;
}

void deleteMovie(MovieNode* movie){
  if (movie == NULL){
    return;
  } 
  deleteMovie(movie->left);
  deleteMovie(movie->right);
  delete movie;
}

MovieTree::~MovieTree() {
  //write your code
  deleteMovie(root);
}

void printMovieInventoryHelper(MovieNode* movie){
  if (movie == NULL){
    return;
  }
  if (movie->left!=NULL){
    printMovieInventoryHelper(movie->left);
  } 
  cout << "Movie: " << movie->title << " " << movie->rating << endl;
  if(movie->right!=NULL){
    printMovieInventoryHelper(movie->right);
  }
}

void MovieTree::printMovieInventory() {
  //write your code
  if (root == NULL){
    cout << "Tree is Empty. Cannot print" << endl;
  } else{
    printMovieInventoryHelper(root);
  }
}

MovieNode* addMovieHelper(MovieNode* newMovie, MovieNode* movie){
  if (movie == NULL){
    return newMovie;
  }
  int tempChar = tolower(movie->title[0]);
  int newChar = tolower(newMovie->title[0]);
  if (tempChar == newChar){
    int count = 1;
    while (tempChar == newChar){
      tempChar = tolower(movie->title[count]);
      newChar = tolower(newMovie->title[count]);
      count++;
    }
  }
  
  if (tempChar > newChar){
    movie->left = addMovieHelper(newMovie, movie->left);
  } else if (tempChar < newChar) {
    movie->right = addMovieHelper(newMovie, movie->right);
  }
  return movie;
}

void MovieTree::addMovieNode(int ranking, string title, int year, float rating) {
  //write your code
  MovieNode* newMovie = new MovieNode;
  newMovie->ranking = ranking;
  newMovie->title = title;
  newMovie->year = year;
  newMovie->rating = rating;
  MovieNode* temp = root;
  root = addMovieHelper(newMovie, root);
}

MovieNode* findMovieHelper(string title, MovieNode* movie){  
  if (movie == NULL){
    return NULL;
  }
  
  int searchChar = tolower(title[0]);
  int movieChar = tolower(movie->title[0]);  

  if (movie->title == title){
    return movie;
  }

  if (searchChar == movieChar){
    int count = 1;
    while(searchChar == movieChar){
      searchChar = tolower(title[count]);
      movieChar = tolower(movie->title[count]);
      count++;
    }
  }
  
  if (searchChar < movieChar){
    return findMovieHelper(title, movie->left);
  } else if(searchChar > movieChar){
    return findMovieHelper(title, movie->right);
  }
}

void MovieTree::findMovie(string title) {
  //write your code
  MovieNode* movie = findMovieHelper(title, root);
  if (movie == NULL){
    cout << "Movie not found." << endl;
  } else {
    cout << "Movie Info:" << endl;
    cout << "==================" << endl;
    cout << "Ranking:" << movie->ranking << endl;
    cout << "Title  :" << movie->title << endl;
    cout << "Year   :" << movie->year << endl;
    cout << "rating :" << movie->rating << endl;
  }
}

void queryMoviesHelper(MovieNode* root, float rating, int year){
  if (root == NULL){
    return;
  }
  if (root->rating >= rating && root->year > year){
    cout << root->title << "(" << root->year << ") " << root->rating << endl;
  }
  queryMoviesHelper(root->left, rating, year);
  queryMoviesHelper(root->right, rating, year); 
}

void MovieTree::queryMovies(float rating, int year) {
  //write your code
  if (root == NULL){
    cout << "Tree is Empty. Cannot query Movies" << endl;
  } else {
    cout << "Movies that came out after " << year << " with rating at least " << rating << ":" << endl;
    queryMoviesHelper(root, rating, year);
  }
  
}

float getSum(MovieNode* root){
  float leftSum, rightSum;
  if (root == NULL){
    return 0;
  } else {
    leftSum = getSum(root->left);
    rightSum = getSum(root->right);
    return root->rating + leftSum + rightSum;
  }
}

int getCount(MovieNode* root){
  int leftCount, rightCount;
  if (root == NULL){
    return 0;
  } else {
    leftCount = getCount(root->left);
    rightCount = getCount(root->right);
    return 1 + leftCount + rightCount;
  }
}

void MovieTree::averageRating() {
  //write your code
  if (root == NULL){
    cout << "Average rating:0.0" << endl;
    return;
  }
  float sum = getSum(root);
  int count = getCount(root);
  cout << "Average rating:" << sum/count << endl;
}

int getDepth(MovieNode* movie){
  if (movie == NULL){
    return 0;
  }
  int left = getDepth(movie->left);
  int right = getDepth(movie->right);
  if (left > right){
    return 1 + left;
  } else {
    return 1 + right;
  } 
}

int depthOfNode(MovieNode* start, MovieNode* end){
  if(start == end){
    return 1;
  }
  if (start == NULL){
    return 0;
  }

  int searchChar = tolower(end->title[0]);
  int movieChar = tolower(start->title[0]);
  
  if (searchChar == movieChar){
    int count = 1;
    while(searchChar == movieChar){
      searchChar = tolower(end->title[count]);
      movieChar = tolower(start->title[count]);
      count++;
    }
  }
  
  if (searchChar < movieChar){
    return 1 + depthOfNode(start->left, end);
  } else if (searchChar > movieChar){
    return 1 + depthOfNode(start->right, end);
  }
}

void levelHelper(MovieNode* movie, MovieNode* root, int k, int max_depth){
  if (movie == NULL){
    return;
  }
  
  if (k == depthOfNode(root, movie)-1){
    cout << "Movie: " << movie->title << " " << movie->rating << endl;
  } else {
    levelHelper(movie->left, root, k, max_depth);
    levelHelper(movie->right, root, k, max_depth);
  }
}

void MovieTree::printLevelNodes(int k) {
  //write your code
  if (root == NULL){
    return;
  }
  int max_depth = getDepth(root) - 1;
  if (!(k > max_depth)){
    levelHelper(root, root, k, max_depth);
  }
}

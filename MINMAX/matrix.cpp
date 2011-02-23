//
//#include <vector>
//#include <cassert>
//#include <iostream>
//
///**
// * \brief Une classe de matrice pleine
// */
//
//template <class T> class matrix{
//    protected:
//        std::vector<std::vector<T> > data;
//    public:
//
//        /**
//         * \brief Constructeur par defaut
//         */
//        matrix(){}
//
//        /**
//         * \brief Alloue en memoire une matrice
//         * \param nb_lig Nombre de ligne
//         * \param nb_col Nombre de colonne
//         */
//        matrix(std::size_t nb_lig,std::size_t nb_col){
//            for(std::size_t lig=0;lig<nb_lig;++lig){
//                std::vector<T> tmp;
//                tmp.reserve(nb_col);
//                for(std::size_t col=0;col<nb_col;++col){
//                    tmp.push_back(0);//valeur par defaut
//                }
//                data.push_back(tmp);
//            }
//        }
//
//        /**
//         * \brief Destructeur
//         */
//        ~matrix(){}
//
//        /**
//         * \return Le nombre de ligne
//         */
//        inline std::size_t size1() const{
//            return data.size();
//        }
//
//        /**
//         * \return Le nombre de colonne
//         */
//        inline std::size_t size2() const{
//            if (data.size()==0) return 0;
//            return data[0].size();
//        }
//
//        /**
//         * \brief Accesseur vers un element de la matrice
//         * \param lig son numero de ligne
//         * \param col son numero de colonne
//         * \return la valeur stockee
//         */
//        inline T get(std::size_t lig,std::size_t col) const{
//            assert(lig<size1());
//            assert(col<size2());
//            return data[lig][col];
//        }
//
//        /**
//         * \brief Accesseur vers un element de la matrice
//         * \param lig son numero de ligne
//         * \param col son numero de colonne
//         * \param val la valeur a stocker
//         */
//        inline void set(std::size_t lig,std::size_t col,T val){
//            assert(lig<size1());
//            assert(col<size2());
//            data[lig][col]=val;
//        }
//
//};
//
///**
// * \brief Operateur << pour les matrices
// * \param o Le flux de sortie
// * \param m la matrice a ecrire
// */
//template <class T>
//std::ostream& operator << (std::ostream& o,const matrix<T> & m){
//    for(std::size_t lig=0;lig<m.size1();++lig){
//        for(std::size_t col=0;col<m.size2();++col){
//            o<<m.get(lig,col)<<" ";
//        }
//        o<<std::endl;
//    }
//    return o;
//}
//
///**
// * \brief Addition matricielle
// * \param m1 la premiere matrice
// * \param m2 la deuxieme matrice
// * \return la somme
// */
//template <class T>
//matrix<T> operator+ (const matrix<T> & m1,const matrix<T> & m2){
//    assert(m1.size1()==m1.size1());
//    assert(m1.size2()==m1.size2());
//    std::size_t nb_lig=m1.size1();
//    std::size_t nb_col=m1.size2();
//    matrix<T> sum(nb_lig,nb_col);
//    for(std::size_t lig=0;lig<nb_lig;++lig){
//        for(std::size_t col=0;col<nb_col;++col){
//            sum.set(lig,col,m1.get(lig,col)+m2.get(lig,col));
//        }
//    }
//    return sum;
//}
//
///**
// * \brief Multiplication matricielle
// * \param m1 la premiere matrice
// * \param m2 la deuxieme matrice
// * \return le produit
// */
//template <class T>
//matrix<T> operator* (const matrix<T> & m1,const matrix<T> & m2){
//
//    assert(m1.size2()==m2.size1());
//    std::size_t nb_lig=m1.size1();
//    std::size_t nb_col=m2.size2();
//    matrix<T> prod(nb_lig,nb_col);
//    for(std::size_t lig=0;lig<nb_lig;++lig){
//        for(std::size_t col=0;col<nb_col;++col){
//            //calcul du terme (lig,col)
//            T tmp=0;
//            for(std::size_t i=0;i<m1.size2();++i){
//                tmp+=m1.get(lig,i)*m2.get(i,col);
//            }
//            prod.set(lig,col,tmp);
//        }
//    }
//    return prod;
//}
//
//int main(){
//    matrix<int> m(3,4);
//    matrix<int> n(3,4);
//    matrix<int> p(4,5);
//    std::cout<<"M est une matrice de dimension :";
//    std::cout<<"("<<m.size1()<<";"<<m.size2()<<")"<<std::endl;
//
//    for(std::size_t lig=0;lig<m.size1();++lig){
//        for(std::size_t col=0;col<m.size2();++col){
//            m.set(lig,col,10*lig+col); //initialisation de m
//            n.set(lig,col,lig*col);    //initialisation de n
//        }
//    }
//
//    for(std::size_t lig=0;lig<p.size1();++lig){
//        for(std::size_t col=0;col<p.size2();++col){
//            p.set(lig,col,lig*col);    //initialisation de n
//        }
//    }
//
//    std::cout<<"M="<<std::endl<<m;
//    std::cout<<"N="<<std::endl<<n;
//    std::cout<<"P="<<std::endl<<p;
//    std::cout<<"M+N="<<std::endl<<m+n;
//    std::cout<<"M*P="<<std::endl<<m*p;
//    return 0;
//}
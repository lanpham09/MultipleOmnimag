#include <QtGui/QApplication>
#include "mainwindow.h"

#include "Producers/TwoOmnimagnet_SingularDirectionProducer.h"
#include "Producers/PositionProducer.h"
#include "Producers/ConstantPositionProducer.h"
#include "Utilities/Math.h" // Defines Position and Direction

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    
    return a.exec();

/*
  // Checking out TwoOmnimagnet_SingularDirectionProducer

    ConstantPositionProducer OmniOnePP( Position(1,0,0,Math::WORLD_FRAME) );
    ConstantPositionProducer OmniTwoPP( Position(0,0,0,Math::WORLD_FRAME) );
    ConstantPositionProducer ToolPP( Position(1,1,0,Math::WORLD_FRAME) );


    TwoOmnimagnet_SingularDirectionProducer SDP( &OmniOnePP, &OmniTwoPP, &ToolPP, TwoOmnimagnet_SingularDirectionProducer::OUT_OF_PLANE );

    Direction dir;
    SDP.getDirection(dir);

    cout << dir.x() << "   " << dir.y() << "   " << dir.z() << endl;

    MagneticToolProducer magTool(&ToolPP, DipoleMoment(1), dir, ForceVector(0,0,-1,Math::WORLD_FRAME));

    SinglePerminantMagnetTool tool(&magTool);

    Eigen::MatrixXd A;

    std::vector < Math::Position > Omnimaglist = {OmniOnePP.returnPosition(), OmniTwoPP.returnPosition()};

    tool.getMatrix(A,Omnimaglist,magneticActuationMatrixProducer::FIELD_FORCE);

    Eigen::JacobiSVD<Eigen::MatrixXd> svd(A, Eigen::ComputeFullU | Eigen::ComputeFullV ); // computes the SVD

    cout << svd.singularValues().transpose();

*/
}

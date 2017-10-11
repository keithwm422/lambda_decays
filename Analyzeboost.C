#include <TLorentzVector.h>
#include <TVector3.h>
#include <TRandom.h>
#include <TProfile.h>
#include <iostream> 
#include <TCanvas.h>
using namespace std;

float lab (TVector3 *b_b);	//Pass it the boost vector, boost the angular momentum, and return the boosted angular momentum
void Analyzeboost()
{
	const int i_max = 500000;
	float pi = 3.14159265358979323846;
	TProfile *pols = new TProfile ("L boosting", "Boosting L", );
//	TProfile *pols_1 = new TProfile ("polarization without cuts", "polarization without cuts",3, 0, 3);
	float beta = 0.85;
	TRandom *rand = new TRandom(0);
	TCanvas *c1 = new TCanvas("L boost","multipads",900,700);	
	for(int i = 0; i <= i_max; i++)
	{
		float Phi= rand->Uniform(0,2*pi);
		float Theta = rand->Uniform(-1, 1);
		float STheta = TMath::Sqrt(1-ThetaLam*ThetaLam);
		// Lambda frame first
		TVector3 b_b(Theta*TMath::Cos(Phi), STheta*TMath::Sin(Phi), Theta);

		TLorentzVector mom_pion_four(mom_pion, TMath::Sqrt(pion_mass*pion_mass+mom_pion.Mag2()));

	}
	c1->SaveAs("neg_pion_nocuts.pdf");
}

float lab (TVector3 *b_b) // 
{
	float polarization = 0.0;
	TLorentzVector spin_four(0.5*mom_proton->Unit(), 0.0);
	spin_four.Boost(*b_b);
	TVector3 spin(spin_four.Vect());
	TVector3 angular(0.6,0.8, 0.05);
	polarization = spin.Dot(angular)/(spin.Mag()*angular.Mag());
	return polarization;
}


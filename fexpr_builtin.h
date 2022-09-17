/*
    Copyright (C) 2021 Fredrik Johansson

    This file is part of Calcium.

    Calcium is free software: you can redistribute it and/or modify it under
    the terms of the GNU Lesser General Public License (LGPL) as published
    by the Free Software Foundation; either version 2.1 of the License, or
    (at your option) any later version.  See <http://www.gnu.org/licenses/>.
*/

#ifndef FEXPR_BUILTIN_H
#define FEXPR_BUILTIN_H

#ifdef FEXPR_BUILTIN_INLINES_C
#define FEXPR_BUILTIN_INLINE
#else
#define FEXPR_BUILTIN_INLINE static __inline__
#endif

#ifdef __cplusplus
extern "C" {
#endif

#include "fexpr.h"

/* Builtin symbols */

/* Must be listed in alphabetical order with corresponding entry
   in fexpr_builtin_table (the alphabetical order is just so that
   we can do binary search on the strings). */
typedef enum
{
    FEXPR_AGM,
    FEXPR_AGMSequence,
    FEXPR_Abs,
    FEXPR_Acos,
    FEXPR_Acosh,
    FEXPR_Acot,
    FEXPR_Acoth,
    FEXPR_Acsc,
    FEXPR_Acsch,
    FEXPR_Add,
    FEXPR_AiryAi,
    FEXPR_AiryAiZero,
    FEXPR_AiryBi,
    FEXPR_AiryBiZero,
    FEXPR_AlgebraicNumberSerialized,
    FEXPR_AlgebraicNumbers,
    FEXPR_All,
    FEXPR_AnalyticContinuation,
    FEXPR_And,
    FEXPR_AngleBrackets,
    FEXPR_Approximation,
    FEXPR_Arg,
    FEXPR_ArgMax,
    FEXPR_ArgMaxUnique,
    FEXPR_ArgMin,
    FEXPR_ArgMinUnique,
    FEXPR_Asec,
    FEXPR_Asech,
    FEXPR_Asin,
    FEXPR_Asinh,
    FEXPR_AsymptoticTo,
    FEXPR_Atan,
    FEXPR_Atan2,
    FEXPR_Atanh,
    FEXPR_BarnesG,
    FEXPR_BellNumber,
    FEXPR_BernoulliB,
    FEXPR_BernoulliPolynomial,
    FEXPR_BernsteinEllipse,
    FEXPR_BesselI,
    FEXPR_BesselJ,
    FEXPR_BesselJZero,
    FEXPR_BesselK,
    FEXPR_BesselY,
    FEXPR_BesselYZero,
    FEXPR_BetaFunction,
    FEXPR_Binomial,
    FEXPR_Braces,
    FEXPR_Brackets,
    FEXPR_CC,
    FEXPR_Call,
    FEXPR_CallIndeterminate,
    FEXPR_Cardinality,
    FEXPR_CarlsonHypergeometricR,
    FEXPR_CarlsonHypergeometricT,
    FEXPR_CarlsonRC,
    FEXPR_CarlsonRD,
    FEXPR_CarlsonRF,
    FEXPR_CarlsonRG,
    FEXPR_CarlsonRJ,
    FEXPR_CartesianPower,
    FEXPR_CartesianProduct,
    FEXPR_Case,
    FEXPR_Cases,
    FEXPR_CatalanConstant,
    FEXPR_Ceil,
    FEXPR_Characteristic,
    FEXPR_ChebyshevT,
    FEXPR_ChebyshevU,
    FEXPR_ClosedComplexDisk,
    FEXPR_ClosedOpenInterval,
    FEXPR_Coefficient,
    FEXPR_Column,
    FEXPR_ColumnMatrix,
    FEXPR_CommutativeRings,
    FEXPR_ComplexBranchDerivative,
    FEXPR_ComplexDerivative,
    FEXPR_ComplexInfinities,
    FEXPR_ComplexLimit,
    FEXPR_ComplexSignedInfinities,
    FEXPR_ComplexSingularityClosure,
    FEXPR_ComplexZeroMultiplicity,
    FEXPR_Concatenation,
    FEXPR_CongruentMod,
    FEXPR_Conjugate,
    FEXPR_ConreyGenerator,
    FEXPR_Cos,
    FEXPR_CosIntegral,
    FEXPR_Cosh,
    FEXPR_CoshIntegral,
    FEXPR_Cot,
    FEXPR_Coth,
    FEXPR_CoulombC,
    FEXPR_CoulombF,
    FEXPR_CoulombG,
    FEXPR_CoulombH,
    FEXPR_CoulombSigma,
    FEXPR_Csc,
    FEXPR_Csch,
    FEXPR_Csgn,
    FEXPR_CurvePath,
    FEXPR_Cyclotomic,
    FEXPR_Decimal,
    FEXPR_DedekindEta,
    FEXPR_DedekindEtaEpsilon,
    FEXPR_DedekindSum,
    FEXPR_Def,
    FEXPR_Delta,
    FEXPR_Delta_,
    FEXPR_Derivative,
    FEXPR_Det,
    FEXPR_DiagonalMatrix,
    FEXPR_DigammaFunction,
    FEXPR_DigammaFunctionZero,
    FEXPR_DirichletCharacter,
    FEXPR_DirichletGroup,
    FEXPR_DirichletL,
    FEXPR_DirichletLZero,
    FEXPR_DirichletLambda,
    FEXPR_DiscreteLog,
    FEXPR_Div,
    FEXPR_Divides,
    FEXPR_DivisorProduct,
    FEXPR_DivisorSigma,
    FEXPR_DivisorSum,
    FEXPR_DoubleFactorial,
    FEXPR_EisensteinE,
    FEXPR_EisensteinG,
    FEXPR_Element,
    FEXPR_Ellipsis,
    FEXPR_EllipticE,
    FEXPR_EllipticK,
    FEXPR_EllipticPi,
    FEXPR_EllipticRootE,
    FEXPR_Enclosure,
    FEXPR_Equal,
    FEXPR_EqualAndElement,
    FEXPR_EqualNearestDecimal,
    FEXPR_EqualQSeriesEllipsis,
    FEXPR_Equivalent,
    FEXPR_Erf,
    FEXPR_Erfc,
    FEXPR_Erfi,
    FEXPR_Euler,
    FEXPR_EulerE,
    FEXPR_EulerPhi,
    FEXPR_EulerPolynomial,
    FEXPR_EulerQSeries,
    FEXPR_Exists,
    FEXPR_Exp,
    FEXPR_ExpIntegralE,
    FEXPR_ExpIntegralEi,
    FEXPR_ExtendedRealNumbers,
    FEXPR_Factorial,
    FEXPR_FallingFactorial,
    FEXPR_False,
    FEXPR_Fibonacci,
    FEXPR_Fields,
    FEXPR_FiniteField,
    FEXPR_Floor,
    FEXPR_For,
    FEXPR_FormalLaurentSeries,
    FEXPR_FormalPowerSeries,
    FEXPR_FormalPuiseuxSeries,
    FEXPR_FresnelC,
    FEXPR_FresnelS,
    FEXPR_Fun,
    FEXPR_GCD,
    FEXPR_Gamma,
    FEXPR_GaussLegendreWeight,
    FEXPR_GaussSum,
    FEXPR_GegenbauerC,
    FEXPR_GeneralLinearGroup,
    FEXPR_GeneralizedBernoulliB,
    FEXPR_GeneralizedRiemannHypothesis,
    FEXPR_GlaisherConstant,
    FEXPR_GoldenRatio,
    FEXPR_Greater,
    FEXPR_GreaterEqual,
    FEXPR_GreekGamma,
    FEXPR_GreekGamma_,
    FEXPR_GreekPi,
    FEXPR_GreekPi_,
    FEXPR_Guess,
    FEXPR_HankelH1,
    FEXPR_HankelH2,
    FEXPR_HarmonicNumber,
    FEXPR_HermiteH,
    FEXPR_HilbertClassPolynomial,
    FEXPR_HilbertMatrix,
    FEXPR_HurwitzZeta,
    FEXPR_Hypergeometric0F1,
    FEXPR_Hypergeometric0F1Regularized,
    FEXPR_Hypergeometric1F1,
    FEXPR_Hypergeometric1F1Regularized,
    FEXPR_Hypergeometric1F2,
    FEXPR_Hypergeometric1F2Regularized,
    FEXPR_Hypergeometric2F0,
    FEXPR_Hypergeometric2F1,
    FEXPR_Hypergeometric2F1Regularized,
    FEXPR_Hypergeometric2F2,
    FEXPR_Hypergeometric2F2Regularized,
    FEXPR_Hypergeometric3F2,
    FEXPR_Hypergeometric3F2Regularized,
    FEXPR_HypergeometricU,
    FEXPR_HypergeometricUStar,
    FEXPR_HypergeometricUStarRemainder,
    FEXPR_IdentityMatrix,
    FEXPR_Im,
    FEXPR_Implies,
    FEXPR_IncompleteBeta,
    FEXPR_IncompleteBetaRegularized,
    FEXPR_IncompleteEllipticE,
    FEXPR_IncompleteEllipticF,
    FEXPR_IncompleteEllipticPi,
    FEXPR_IndefiniteIntegralEqual,
    FEXPR_Infimum,
    FEXPR_Infinity,
    FEXPR_IntegersGreaterEqual,
    FEXPR_IntegersLessEqual,
    FEXPR_Integral,
    FEXPR_Intersection,
    FEXPR_Interval,
    FEXPR_IsEven,
    FEXPR_IsHolomorphicOn,
    FEXPR_IsMeromorphicOn,
    FEXPR_IsOdd,
    FEXPR_IsPrime,
    FEXPR_Item,
    FEXPR_JacobiP,
    FEXPR_JacobiSymbol,
    FEXPR_JacobiTheta,
    FEXPR_JacobiThetaEpsilon,
    FEXPR_JacobiThetaPermutation,
    FEXPR_JacobiThetaQ,
    FEXPR_KeiperLiLambda,
    FEXPR_KhinchinConstant,
    FEXPR_KroneckerDelta,
    FEXPR_KroneckerSymbol,
    FEXPR_LCM,
    FEXPR_LaguerreL,
    FEXPR_LambertW,
    FEXPR_Lamda,
    FEXPR_Lamda_,
    FEXPR_LandauG,
    FEXPR_Lattice,
    FEXPR_LeftLimit,
    FEXPR_LegendreP,
    FEXPR_LegendrePolynomialZero,
    FEXPR_LegendreSymbol,
    FEXPR_Length,
    FEXPR_LerchPhi,
    FEXPR_Less,
    FEXPR_LessEqual,
    FEXPR_Limit,
    FEXPR_LiouvilleLambda,
    FEXPR_List,
    FEXPR_Log,
    FEXPR_LogBarnesG,
    FEXPR_LogBarnesGRemainder,
    FEXPR_LogGamma,
    FEXPR_LogIntegral,
    FEXPR_Logic,
    FEXPR_LowerGamma,
    FEXPR_Matrices,
    FEXPR_Matrix,
    FEXPR_Matrix2x2,
    FEXPR_Max,
    FEXPR_Maximum,
    FEXPR_MeromorphicDerivative,
    FEXPR_MeromorphicLimit,
    FEXPR_Min,
    FEXPR_Minimum,
    FEXPR_Mod,
    FEXPR_ModularGroupAction,
    FEXPR_ModularGroupFundamentalDomain,
    FEXPR_ModularJ,
    FEXPR_ModularLambda,
    FEXPR_ModularLambdaFundamentalDomain,
    FEXPR_MoebiusMu,
    FEXPR_Mul,
    FEXPR_MultiZetaValue,
    FEXPR_NN,
    FEXPR_Neg,
    FEXPR_Not,
    FEXPR_NotElement,
    FEXPR_NotEqual,
    FEXPR_NumberE,
    FEXPR_NumberI,
    FEXPR_Omega,
    FEXPR_Omega_,
    FEXPR_One,
    FEXPR_OpenClosedInterval,
    FEXPR_OpenComplexDisk,
    FEXPR_OpenInterval,
    FEXPR_OpenRealBall,
    FEXPR_Or,
    FEXPR_Otherwise,
    FEXPR_PSL2Z,
    FEXPR_Parentheses,
    FEXPR_PartitionsP,
    FEXPR_Path,
    FEXPR_Phi,
    FEXPR_Phi_,
    FEXPR_Pi,
    FEXPR_Pol,
    FEXPR_Poles,
    FEXPR_PolyLog,
    FEXPR_Polynomial,
    FEXPR_PolynomialDegree,
    FEXPR_PolynomialFractions,
    FEXPR_PolynomialRootIndexed,
    FEXPR_PolynomialRootNearest,
    FEXPR_Polynomials,
    FEXPR_Pos,
    FEXPR_Pow,
    FEXPR_Prime,
    FEXPR_PrimePi,
    FEXPR_PrimeProduct,
    FEXPR_PrimeSum,
    FEXPR_Primes,
    FEXPR_PrimitiveDirichletCharacters,
    FEXPR_PrimitiveReducedPositiveIntegralBinaryQuadraticForms,
    FEXPR_Product,
    FEXPR_ProjectiveComplexNumbers,
    FEXPR_ProjectiveRealNumbers,
    FEXPR_Psi,
    FEXPR_Psi_,
    FEXPR_QQ,
    FEXPR_QSeriesCoefficient,
    FEXPR_QuotientRing,
    FEXPR_RR,
    FEXPR_Range,
    FEXPR_Re,
    FEXPR_RealAbs,
    FEXPR_RealAlgebraicNumbers,
    FEXPR_RealBall,
    FEXPR_RealDerivative,
    FEXPR_RealInfinities,
    FEXPR_RealLimit,
    FEXPR_RealSignedInfinities,
    FEXPR_RealSingularityClosure,
    FEXPR_Repeat,
    FEXPR_Residue,
    FEXPR_RiemannHypothesis,
    FEXPR_RiemannXi,
    FEXPR_RiemannZeta,
    FEXPR_RiemannZetaZero,
    FEXPR_RightLimit,
    FEXPR_Rings,
    FEXPR_RisingFactorial,
    FEXPR_Root,
    FEXPR_RootOfUnity,
    FEXPR_Row,
    FEXPR_RowMatrix,
    FEXPR_SL2Z,
    FEXPR_Same,
    FEXPR_Sec,
    FEXPR_Sech,
    FEXPR_SequenceLimit,
    FEXPR_SequenceLimitInferior,
    FEXPR_SequenceLimitSuperior,
    FEXPR_Ser,
    FEXPR_Set,
    FEXPR_SetMinus,
    FEXPR_Sets,
    FEXPR_ShowExpandedNormalForm,
    FEXPR_Sigma,
    FEXPR_Sigma_,
    FEXPR_Sign,
    FEXPR_SignExtendedComplexNumbers,
    FEXPR_Sin,
    FEXPR_SinIntegral,
    FEXPR_Sinc,
    FEXPR_SingularValues,
    FEXPR_Sinh,
    FEXPR_SinhIntegral,
    FEXPR_SloaneA,
    FEXPR_Solutions,
    FEXPR_SpecialLinearGroup,
    FEXPR_Spectrum,
    FEXPR_SphericalHarmonicY,
    FEXPR_Sqrt,
    FEXPR_SquaresR,
    FEXPR_Step,
    FEXPR_StieltjesGamma,
    FEXPR_StirlingCycle,
    FEXPR_StirlingS1,
    FEXPR_StirlingS2,
    FEXPR_StirlingSeriesRemainder,
    FEXPR_Sub,
    FEXPR_Subscript,
    FEXPR_Subset,
    FEXPR_SubsetEqual,
    FEXPR_Subsets,
    FEXPR_Sum,
    FEXPR_Supremum,
    FEXPR_SymmetricPolynomial,
    FEXPR_Tan,
    FEXPR_Tanh,
    FEXPR_Theta,
    FEXPR_Theta_,
    FEXPR_TribonacciConstant,
    FEXPR_True,
    FEXPR_Tuple,
    FEXPR_Tuples,
    FEXPR_Undefined,
    FEXPR_Union,
    FEXPR_UniqueSolution,
    FEXPR_UniqueZero,
    FEXPR_UnitCircle,
    FEXPR_Unknown,
    FEXPR_UnsignedInfinity,
    FEXPR_UpperGamma,
    FEXPR_UpperHalfPlane,
    FEXPR_WeierstrassP,
    FEXPR_WeierstrassSigma,
    FEXPR_WeierstrassZeta,
    FEXPR_Where,
    FEXPR_XGCD,
    FEXPR_XX,
    FEXPR_Xi,
    FEXPR_Xi_,
    FEXPR_ZZ,
    FEXPR_Zero,
    FEXPR_ZeroMatrix,
    FEXPR_Zeros,
    FEXPR_alpha,
    FEXPR_alpha_,
    FEXPR_beta,
    FEXPR_beta_,
    FEXPR_chi,
    FEXPR_chi_,
    FEXPR_delta,
    FEXPR_delta_,
    FEXPR_ell,
    FEXPR_ell_,
    FEXPR_epsilon,
    FEXPR_epsilon_,
    FEXPR_eta,
    FEXPR_eta_,
    FEXPR_gamma,
    FEXPR_gamma_,
    FEXPR_iota,
    FEXPR_iota_,
    FEXPR_kappa,
    FEXPR_kappa_,
    FEXPR_lamda,
    FEXPR_lamda_,
    FEXPR_mu,
    FEXPR_mu_,
    FEXPR_nu,
    FEXPR_nu_,
    FEXPR_omega,
    FEXPR_omega_,
    FEXPR_phi,
    FEXPR_phi_,
    FEXPR_pi,
    FEXPR_pi_,
    FEXPR_rho,
    FEXPR_rho_,
    FEXPR_sigma,
    FEXPR_sigma_,
    FEXPR_tau,
    FEXPR_tau_,
    FEXPR_theta,
    FEXPR_theta_,
    FEXPR_varphi,
    FEXPR_varphi_,
    FEXPR_vartheta,
    FEXPR_vartheta_,
    FEXPR_xi,
    FEXPR_xi_,
    FEXPR_zeta,
    FEXPR_zeta_,
    FEXPR_BUILTIN_LENGTH
}
fexpr_builtin_symbol;

typedef void (*_fexpr_latex_writer)(calcium_stream_t, const fexpr_t, ulong);

typedef struct
{
    fexpr_builtin_symbol symbol;
    const char * string;
    const char * latex_string;
    _fexpr_latex_writer latex_writer;
}
fexpr_symbol_info;

extern const fexpr_symbol_info fexpr_builtin_table[FEXPR_BUILTIN_LENGTH];

#define FEXPR_SYMBOL_Pos  (FEXPR_TYPE_SMALL_SYMBOL | (FEXPR_Pos << 16))
#define FEXPR_SYMBOL_Neg  (FEXPR_TYPE_SMALL_SYMBOL | (FEXPR_Neg << 16))
#define FEXPR_SYMBOL_Add  (FEXPR_TYPE_SMALL_SYMBOL | (FEXPR_Add << 16))
#define FEXPR_SYMBOL_Sub  (FEXPR_TYPE_SMALL_SYMBOL | (FEXPR_Sub << 16))
#define FEXPR_SYMBOL_Mul  (FEXPR_TYPE_SMALL_SYMBOL | (FEXPR_Mul << 16))
#define FEXPR_SYMBOL_Div  (FEXPR_TYPE_SMALL_SYMBOL | (FEXPR_Div << 16))
#define FEXPR_SYMBOL_Pow  (FEXPR_TYPE_SMALL_SYMBOL | (FEXPR_Pow << 16))

slong fexpr_builtin_lookup(const char * s);

FEXPR_BUILTIN_INLINE 
const char * fexpr_builtin_name(slong n)
{
    return fexpr_builtin_table[n].string;
}

FEXPR_BUILTIN_INLINE slong fexpr_builtin_length(void)
{
    return FEXPR_BUILTIN_LENGTH;
}

#ifdef __cplusplus
}
#endif

#endif


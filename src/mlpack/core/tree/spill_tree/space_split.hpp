/**
 * @file space_split.hpp
 * @author Marcos Pividori
 *
 * Definition of MidpointSpaceSplit and MeanSpaceSplit, to create a splitting
 * hyperplane considering the midpoint/mean of the values in a certain
 * projection.
 */
#ifndef MLPACK_CORE_TREE_SPILL_TREE_SPACE_SPLIT_HPP
#define MLPACK_CORE_TREE_SPILL_TREE_SPACE_SPLIT_HPP

#include <mlpack/core.hpp>
#include "hyperplane.hpp"

namespace mlpack {
namespace tree {

template<typename MetricType, typename MatType>
class MeanSpaceSplit
{
 public:
  /**
   * Create a splitting hyperplane considering the mean of the values in a
   * certain projection.
   *
   * @param bound The bound used for this node.
   * @param data The dataset used by the tree.
   * @param points Vector of indexes of points to be considered.
   * @param hyp Resulting splitting hyperplane.
   * @return Flag to determine if split is possible.
   */
  template<typename HyperplaneType>
  static bool SplitSpace(
      const typename HyperplaneType::BoundType& bound,
      const MatType& data,
      const arma::Col<size_t>& points,
      HyperplaneType& hyp);
};

template<typename MetricType, typename MatType>
class MidpointSpaceSplit
{
 public:
  /**
   * Create a splitting hyperplane considering the midpoint of the values in a
   * certain projection.
   *
   * @param bound The bound used for this node.
   * @param data The dataset used by the tree.
   * @param points Vector of indexes of points to be considered.
   * @param hyp Resulting splitting hyperplane.
   * @return Flag to determine if split is possible.
   */
  template<typename HyperplaneType>
  static bool SplitSpace(
      const typename HyperplaneType::BoundType& bound,
      const MatType& data,
      const arma::Col<size_t>& points,
      HyperplaneType& hyp);
};

template<typename MetricType, typename MatType>
class SpaceSplit
{
 public:
  /**
   * Create a projection vector based on the given set of point. This special
   * case will create an axis-parallel projection vector in the dimension that
   * has the maximum width.
   *
   * @param bound The bound used for this node.
   * @param data The dataset used by the tree.
   * @param points Vector of indexes of points to be considered.
   * @param projVector Resulting axis-parallel projection vector.
   * @param midValue Mid value in the chosen projection.
   * @return Flag to determine if it is possible.
   */
  static bool GetProjVector(
      const bound::HRectBound<MetricType>& bound,
      const MatType& data,
      const arma::Col<size_t>& points,
      AxisParallelProjVector& projVector,
      double& midValue);

  /**
   * Create a projection vector based on the given set of point. We efficiently
   * estimate the farthest pair of points in the given set: p and q, and then
   * consider the projection vector (q - p).
   *
   * @param bound The bound used for this node.
   * @param data The dataset used by the tree.
   * @param points Vector of indexes of points to be considered.
   * @param projVector Resulting projection vector.
   * @param midValue Mid value in the chosen projection.
   * @return Flag to determine if it is possible.
   */
  template<typename BoundType>
  static bool GetProjVector(
      const BoundType& bound,
      const MatType& data,
      const arma::Col<size_t>& points,
      ProjVector& projVector,
      double& midValue);
};

} // namespace tree
} // namespace mlpack

// Include implementation.
#include "space_split_impl.hpp"

#endif

/*
 * Copyright (c) Meta Platforms, Inc. and affiliates.
 *
 * This source code is licensed under the MIT license found in the
 * LICENSE file in the root directory of this source tree.
 */

#pragma once

#include <memory>

#include <ABI45_0_0React/ABI45_0_0renderer/attributedstring/AttributedStringBox.h>
#include <ABI45_0_0React/ABI45_0_0renderer/attributedstring/ParagraphAttributes.h>
#include <ABI45_0_0React/ABI45_0_0renderer/core/LayoutConstraints.h>
#include <ABI45_0_0React/ABI45_0_0renderer/textlayoutmanager/TextMeasureCache.h>
#include <ABI45_0_0React/ABI45_0_0utils/ContextContainer.h>

namespace ABI45_0_0facebook {
namespace ABI45_0_0React {

class TextLayoutManager;

/*
 * Cross platform facade for iOS-specific ABI45_0_0RCTTTextLayoutManager.
 */
class TextLayoutManager {
 public:
  TextLayoutManager(ContextContainer::Shared const &contextContainer);

  /*
   * Measures `attributedString` using native text rendering infrastructure.
   */
  TextMeasurement measure(
      AttributedStringBox attributedStringBox,
      ParagraphAttributes paragraphAttributes,
      LayoutConstraints layoutConstraints) const;

  /*
   * Measures lines of `attributedString` using native text rendering
   * infrastructure.
   */
  LinesMeasurements measureLines(
      AttributedString attributedString,
      ParagraphAttributes paragraphAttributes,
      Size size) const;

  /*
   * Returns an opaque pointer to platform-specific TextLayoutManager.
   * Is used on a native views layer to delegate text rendering to the manager.
   */
  std::shared_ptr<void> getNativeTextLayoutManager() const;

 private:
  std::shared_ptr<void> self_;
  TextMeasureCache measureCache_{};
};

} // namespace ABI45_0_0React
} // namespace ABI45_0_0facebook

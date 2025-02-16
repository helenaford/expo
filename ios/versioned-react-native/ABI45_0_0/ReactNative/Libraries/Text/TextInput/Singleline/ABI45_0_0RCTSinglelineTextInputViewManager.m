/*
 * Copyright (c) Meta Platforms, Inc. and affiliates.
 *
 * This source code is licensed under the MIT license found in the
 * LICENSE file in the root directory of this source tree.
 */

#import <ABI45_0_0React/ABI45_0_0RCTSinglelineTextInputViewManager.h>

#import <ABI45_0_0React/ABI45_0_0RCTBaseTextInputShadowView.h>
#import <ABI45_0_0React/ABI45_0_0RCTSinglelineTextInputView.h>

@implementation ABI45_0_0RCTSinglelineTextInputViewManager

ABI45_0_0RCT_EXPORT_MODULE()

- (ABI45_0_0RCTShadowView *)shadowView
{
  ABI45_0_0RCTBaseTextInputShadowView *shadowView =
    (ABI45_0_0RCTBaseTextInputShadowView *)[super shadowView];

  shadowView.maximumNumberOfLines = 1;

  return shadowView;
}

- (UIView *)view
{
  return [[ABI45_0_0RCTSinglelineTextInputView alloc] initWithBridge:self.bridge];
}

@end

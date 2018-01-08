#pragma once

#include "IGraphicsConstants.h"

#ifndef NO_IGRAPHICS

class IGraphicsWeb
{
public:
  IGraphicsMac(IPlugBaseGraphics& plug, int w, int h, int fps);
  virtual ~IGraphicsMac();

  void DrawBitmap(IBitmap& bitmap, const IRECT& dest, int srcX, int srcY, const IBlend* pBlend) override;
  void DrawRotatedBitmap(IBitmap& bitmap, int destCtrX, int destCtrY, double angle, int yOffsetZeroDeg, const IBlend* pBlend) override;
  void DrawRotatedMask(IBitmap& base, IBitmap& mask, IBitmap& top, int x, int y, double angle, const IBlend* pBlend) override;
  void DrawPoint(const IColor& color, float x, float y, const IBlend* pBlend, bool aa) override;
  void ForcePixel(const IColor& color, int x, int y) override;
  void DrawLine(const IColor& color, float x1, float y1, float x2, float y2, const IBlend* pBlend, bool aa) override;
  void DrawTriangle(const IColor& color, int x1, int y1, int x2, int y2, int x3, int y3, const IBlend* pBlend) override;
  void DrawArc(const IColor& color, float cx, float cy, float r, float minAngle, float maxAngle,  const IBlend* pBlend, bool aa) override;
  void DrawCircle(const IColor& color, float cx, float cy, float r,const IBlend* pBlend, bool aa) override;
  void DrawRoundRect(const IColor& color, const IRECT& rect, const IBlend* pBlend, int cr, bool aa) override;
  void FillCircle(const IColor& color, int cx, int cy, float r, const IBlend* pBlend, bool aa) override;
  void FillIRect(const IColor& color, const IRECT& rect, const IBlend* pBlend) override;

  void FillRoundRect(const IColor& color, const IRECT& rect, const IBlend* pBlend, int cr, bool aa) override;
  void FillIConvexPolygon(const IColor& color, int* x, int* y, int npoints, const IBlend* pBlend) override;
  void FillTriangle(const IColor& color, int x1, int y1, int x2, int y2, int x3, int y3, const IBlend* pBlend) override;
  
  IColor GetPoint(int x, int y) override;
  void* GetData() override { return nullptr; }

  bool DrawIText(const IText& text, const char* str, IRECT& rect, bool measure) override;
  bool MeasureIText(const IText& text, const char* str, IRECT& destRect) override;
  
  IBitmap LoadIBitmap(const char* name, int nStates, bool framesAreHoriztonal, double scale) override;
  IBitmap ScaleIBitmap(const IBitmap& bitmap, const char* name, double targetScale) override;
  IBitmap CropIBitmap(const IBitmap& bitmap, const IRECT& rect, const char* name, double targetScale) override;
  void ReleaseIBitmap(IBitmap& bitmap) override;
  void RetainIBitmap(IBitmap& bitmap, const char * cacheName) override;

  void DrawScreen(const IRECT& rect) override;
  
  void* OpenWindow(void* pWindow) override;
  void CloseWindow() override;
  void* GetWindow() override;
  bool WindowIsOpen() override;
  void Resize(int w, int h) override;

  void HideMouseCursor() override;
  void ShowMouseCursor() override;

  int ShowMessageBox(const char* str, const char* caption, int type) override;
  void ForceEndUserEdit() override;

  const char* GetGUIAPI() override;
  
  void UpdateTooltips() override;

//   void HostPath(WDL_String& path) override;
//   void PluginPath(WDL_String& path) override;
//   void DesktopPath(WDL_String& path) override;
//   void AppSupportPath(WDL_String& path, bool isSystem = false) override;
//   void SandboxSafeAppSupportPath(WDL_String& path) override;
//   void VST3PresetsPath(WDL_String& path, bool isSystem = true);
//   bool RevealPathInExplorerOrFinder(WDL_String& path, bool select = false) override;

  void PromptForFile(WDL_String& fileName, WDL_String& path, EFileAction action,  const char* ext) override;
  bool PromptForColor(IColor& color, const char* str) override;

  IPopupMenu* CreateIPopupMenu(IPopupMenu& menu, IRECT& rect) override;
  void CreateTextEntry(IControl* pControl, const IText& text, const IRECT& textRect, const char* str, IParam* pParam) override;

  bool OpenURL(const char* url, const char* msgWindowTitle, const char* confirmMsg, const char* errMsgOnFailure) override;

  const char* GetBundleID()  { return mBundleID.Get(); }
  static int GetUserOSVersion();
  
  bool GetTextFromClipboard(WDL_String& str) override;

  bool MeasureIText(const IText& text, const char* str, IRECT& destRect) override;
protected:
  void OSLoadBitmap(const char* name, WDL_String& fullPath) override;
//  void OSLoadFont(const char* name, const int size) override;
//  bool LoadSVGFile(const WDL_String & file, WDL_String & fileOut);
}

#endif
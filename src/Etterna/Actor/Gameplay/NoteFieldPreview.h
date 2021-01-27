#ifndef NOTE_FIELDPREVIEW_H
#define NOTE_FIELDPREVIEW_H

#include "NoteField.h"

class Steps;

class NoteFieldPreview : public NoteField
{
  public:
	void LoadFromNode(const XNode* pNode) override;
	void Update(float fDeltaTime) override;
	void DrawPrimitives() override;
	void LoadNoteData(NoteData* pNoteData);
	void LoadNoteData(Steps* pSteps);
	void LoadDummyNoteData();
	void UpdateDrawDistance(int aftertargetspixels, int beforetargetspixels);
	NoteFieldPreview();
	~NoteFieldPreview();
	[[nodiscard]] auto Copy() const -> NoteFieldPreview* override;
	void PushSelf(lua_State* L) override;

  private:
	NoteData* p_dummyNoteData;
	bool loadedNoteDataAtLeastOnce = false;
};

#endif

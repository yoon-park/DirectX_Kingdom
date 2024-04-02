#include "PreCompile.h"
#include "EngineMesh.h"

UEngineMesh::UEngineMesh()
{

}

UEngineMesh::~UEngineMesh()
{

}

void UEngineMesh::ResCreate(std::string_view _VertexName, std::string_view _IndexName)
{
	VertexBuffer = UEngineVertexBuffer::FindRes(_VertexName);
	IndexBuffer = UEngineIndexBuffer::FindRes(_IndexName);

	if (VertexBuffer == nullptr || IndexBuffer == nullptr)
	{
		MsgBoxAssert("메쉬 생성에 실패했습니다.");
		return;
	}
}
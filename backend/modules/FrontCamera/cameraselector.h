#ifndef CAMERA_SELECTOR_H
#define CAMERA_SELECTOR_H

#include <QObject>
#include <QCamera>
#include <QVideoDeviceSelectorControl>

class CameraSelector : public QObject
{
    Q_OBJECT
    Q_PROPERTY(QObject* cameraObject READ cameraObject WRITE setCameraObject)
    Q_PROPERTY(int selectedCameraDevice READ selectedCameraDevice WRITE setSelectedCameraDevice)

public:
    QObject* cameraObject() const;
    void setCameraObject(QObject *cam);

    int selectedCameraDevice() const;
    void setSelectedCameraDevice(const int cameraId);

private:
    QCamera *m_camera;
    QVideoDeviceSelectorControl *m_deviceSelector;
};

#endif // CAMERA_SELECTOR_H
